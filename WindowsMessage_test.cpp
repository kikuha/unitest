// WindowsMessage_test.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string& input, char delimiter)
{
	istringstream stream(input);
	string field;
	vector<string> result;
	while (getline(stream, field, delimiter)) {
		result.push_back(field);
	}
	return result;
}

int main()
{
    std::cout << "Hello World!\n";


	short pm_x = 258;
	short pm_y = 1900;
	short pm_z = -20;

	printf("%d = %04x \n%d = %04x \n%d = %04x \n\n", pm_x, pm_x, pm_y, pm_y, pm_z, pm_z);
	/////
	//258  =  01 02
	//1900 =  07 6c
	//- 20 = ffff ff ec ->  ff ec 
	////
	
	char xyz[] = { 0x00, 0x00,
		(char)(pm_z >> 8), (byte)(pm_z & 0x00ff),
		(char)(pm_y >> 8), (char)(pm_y & 0x00ff),
		(char)(pm_x >> 8), (char)(pm_x & 0x00ff)
	};

	printf("%02x, %02x,\n %02x,  %02x,\n %02x, %02x,\n %02x, %02x,\n\n",xyz[0],xyz[1],xyz[2],xyz[3], xyz[4], xyz[5],xyz[6],xyz[7]);

	INT64 lParam;
	lParam = *(INT64*)&xyz;
	printf("%llx\n\n", lParam);

	

	ifstream ifs("C:/Users/hkiku/Desktop/210704_htmlwindowtest/test_in_mihon.csv");
	//ifstream ifs("data.csv");

	string output_csv_file_path = "test_out.csv";
	ofstream ofs_csv_file(output_csv_file_path);

	ofs_csv_file << "x,y,z" << endl;

	float pitch = 0.01;
	float y_count = 0;
	
	string line;
	while (getline(ifs, line)) {

		vector<string> strvec = split(line, ',');

		float x_count = 0;

		for (int i = 1; i < strvec.size(); i++) {
			string buf = strvec.at(i);

			ofs_csv_file << to_string(x_count*pitch) << ',' << to_string(y_count*pitch) << ',' << buf << endl;
			x_count += 1;
		}

		y_count += 1;
	}


}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
