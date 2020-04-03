int main() {
	std::ofstream outFile;
	outFile.open("F:\\Test.txt");
	int i;
	int arr[5] = { 1, 2, 3, 4, 5 };
	for (i = 0; i < 5; i++)
	{
		//写入数据
		outFile << arr[i] << endl;
	}
	//关闭文件
	outFile.close();
	return 0;
}