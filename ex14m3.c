/*
ex14m2 の結果をファイルに出力する。
コマンドライン引数で、入力ファイル名と出力ファイル名を指定する。

引数なし、データなしの場合は実行結果のようにメッセージを表示し、出力ファイルには出力しない。
添付の、ex14m2.dat をダウンロードして動作確認すること。
作成 17104088 谷口清彦
*/
#include<stdio.h>
#define LEN 100
#define DATE_LEN 8
#define DATA_MAX 7

struct temperature{
	char date[DATE_LEN + 1];  //日付(yyyymmdd)
	double max;
	double min;
	double diff;
};

void main(int argc, char *argv[]){
	FILE *file;
	FILE *fileWrite;
	int i, num = 1;
	struct temperature temp[DATA_MAX + 1];


	file = fopen(argv[1],"r");	
		for(i=0;fscanf(file,"%s%lf%lf",temp[i].date,&temp[i].max,&temp[i].min) == 3;i++){
	num ++;
			}

	if(argc < 3){
		puts("ファイル名を指定してください");
	}else if(file == NULL){
		puts("データがありませんでした");
	}else if(num > DATA_MAX){
		puts("ファイルが7行を超えています。\n最初の7行のみ処理します。");
		printf("ファイル[%s]の内容\n",argv[1]);
		puts("日付\t\t最高気温\t最低気温\t温度差");
		for(i=0;i<DATA_MAX;i++){
			temp[i].diff = temp[i].max - temp[i].min;
			printf("%s\t%.1lf\t\t%.1lf\t\t%.1lf\n",temp[i].date,temp[i].max,temp[i].min,temp[i].diff);
		}
	}else{	
			num = 0;
			printf("ファイル[%s]の内容\n",argv[1]);
			puts("日付\t最高気温\t最低気温\t温度差");
			for(i=0;fscanf(file,"%s%lf%lf",temp[i].date,&temp[i].max,&temp[i].min) == 3;i++){
				temp[i].diff = temp[i].max - temp[i].min;
				printf("%s\t%.1lf\t\t%.1lf\t\t%.1lf\n",temp[i].date,temp[i].max,temp[i].min,temp[i].diff);
			}
		fclose(file);
	}
	
	
//ファイル
	
	fileWrite = fopen(argv[2],"w");
	
		for(i=0;fscanf(fileWrite,"%s%lf%lf",temp[i].date,&temp[i].max,&temp[i].min) == 3;i++){
	num ++;
			}

	if(argc < 3){
		fprintf(fileWrite,"ファイル名を指定してください\n");
	}else if(file == NULL){
		fprintf(fileWrite,"データがありませんでした\n");
	}else if(num > DATA_MAX){
		fprintf(fileWrite,"ファイルが7行を超えています。\n最初の7行のみ処理します。\n");
		fprintf(fileWrite,"ファイル[%s]の内容\n",argv[1]);
		fprintf(fileWrite,"日付\t\t最高気温\t最低気温\t温度差\n");
		for(i=0;i<DATA_MAX;i++){
			temp[i].diff = temp[i].max - temp[i].min;
			fprintf(fileWrite,"%s\t%.1lf\t\t%.1lf\t\t%.1lf\n",temp[i].date,temp[i].max,temp[i].min,temp[i].diff);
		}
	}else{	
			num = 0;
			fprintf(fileWrite,"ファイル[%s]の内容\n",argv[1]);
			fprintf(fileWrite,"日付\t最高気温\t最低気温\t温度差\n");
			for(i=0;fscanf(fileWrite,"%s%lf%lf",temp[i].date,&temp[i].max,&temp[i].min) == 3;i++){
				temp[i].diff = temp[i].max - temp[i].min;
				fprintf(fileWrite,"%s\t%.1lf\t\t%.1lf\t\t%.1lf\n",temp[i].date,temp[i].max,temp[i].min,temp[i].diff);
			}
		fclose(file);
	}	
	

	
	


}

