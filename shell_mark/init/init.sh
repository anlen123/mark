#!/usr/bin/bash

cat <<-'EOF'
+-------------------------+
|        基本配置         |
|       1.全部            |
|       2.换源并更新      |
|       3.配置zsh         |
|       4.配置neovim      |
|       5.配置docker      |
+-------------------------+

EOF
one(){ #换源
	if [ ! "$USER" = "root" ];then
		echo "请用root命令执行!"
		exit
	fi
	if [ $P_M == "yum" ];then
		$P_M install -y wget
		cp /etc/P_M.repos.d/CentOS-Base.repo /etc/P_M.repos.d/CentOS-Base.repo.bak
		wget -O /etc/P_M.repos.d/CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-7.repo
		cp /etc/P_M.repos.d/epel.repo /etc/P_M.repos.d/epel.repo.bak
		wget -O /etc/P_M.repos.d/epel.repo http://mirrors.aliyun.com/repo/epel-7.repo
		P_M  clean  all
		P_M  makecache
		P_M -y update
	elif [ $P_M == "apt-get" ];then
		sudo cp /etc/apt/sources.list /etc/apt/sources.list_backup
		cat > /etc/apt/sources.list<<-'EOF'
	deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse \
	deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse
	deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
	deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
	deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
	deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
	deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
	deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
	deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse
	deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse

	EOF
		sudo $P_M update
		sudo $P_M upgrade
	fi
	#换源
}

two(){ # 配置zsh的
	cd ~ 
	if ! command -v git&>/dev/null ;then 
		$P_M install -y git
	fi 

	if ! command -v zsh&>/dev/null ;then 
		$P_M install -y zsh
	fi 

	if [ ! -d ~/my_zsh ];then
		git clone https://gitee.com/anlen123/my_zsh
	fi

	if [ $? -eq 0 ];then
		cp -r ~/my_zsh/.zshrc ~
		cp -r ~/my_zsh/.oh-my-zsh ~
		cd ~
		chsh -s /bin/zsh 
		if [ $? -eq 0 ];then 
			cd ~
			rm -rf -R my_zsh
		fi
	fi
	#以上是配置zsh的
}

three(){ #以下是配置nvim的
	cd ~ 
	if ! command -v nvim&>/dev/null ;then 
		$P_M install -y neovim
	fi 

	cd ~
	if [ ! -d ~/.config/nvim ];then 
		mkdir -p ~/.config 
		cd ~/.config  
		if [ $? -eq 0 ];then 
			git clone https://gitee.com/anlen123/nvim
		fi
		
		cd ~
		
	fi
	#以上是配置nvim的
}

four(){ #配置docker
	cd ~
	if ! command -v docker&>/dev/null ;then
		$P_M -y install docker
	fi

	service docker start
	systemctl daemon-reload
	systemctl restart docker.service
	systemctl enable docker

	sudo mkdir -p /etc/docker
	sudo tee /etc/docker/daemon.json <<-'EOF'
	{
	  "registry-mirrors": ["https://gr51o72c.mirror.aliyuncs.com"]
	}
	EOF
	sudo systemctl daemon-reload
	sudo systemctl restart docker
	
	if [ "$(docker ps -a | awk '{print$2}'| grep portainer/portainer)" == "portainer/portainer" ] ;then
		echo "docker可视化已存在"
	else 
		docker run -d -p 9000:9000 --restart=always -v /var/run/docker.sock:/var/run/docker.sock -v portainer_data:/data --name prtainer-test portainer/portainer
	fi

	if [ $? -eq 0 ];then
		docker ps -a 
	fi
}

os_check() { #检查系统
    if [ -e /etc/redhat-release ] ; then
        REDHAT=`cat /etc/redhat-release | cut -d' '  -f1 `
    else
        DEBIAN=`cat /etc/issue | cut -d' '  -f1 `
    fi

    if [ "$REDHAT" == "CentOS" -o "$REDHAT" == "RED" ] ; then 
        P_M=yum
    elif [ "$DEBIAN" == "Ubuntu" -o "$DEBIAN" == "ubuntu" ] ; then 
        P_M=apt-get
    else
        Operating system does not support
        exit 1
    fi
	echo 工具是 "$P_M"
}

echo -en "Please input your number:"
read op
# echo $op
os_check
case "$op" in 
1) 
	one
	two
	three
	four
	;;
2)  
	one
	;;
3)  
	two
	;;
4)
	three
	;;
5) 
	four
	;;
*)
	echo "输入错误!!"
	;;
esac

