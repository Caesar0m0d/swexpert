#include<bits/stdc++.h>
using namespace std;
map<string,int> mapp;
char tt[8];
char arr[6][6];
int ans;
int dfs(int x, int y, int turn){
	int i,j;tt[turn] = arr[x][y];
	//map comparison
	if(turn == 6){
		if(mapp.find(tt) == mapp.end()){
			cout<<tt<<endl;
			ans++;
			mapp.insert(make_pair(tt,1));
		}
		tt[turn]=0;return 0;
	}
	if(x+1 != 5)dfs(x+1,y,turn+1);
	if(x-1 != 0)dfs(x-1,y,turn+1);
	if(y+1 != 5)dfs(x,y+1,turn+1);
	if(y-1 != 0)dfs(x,y-1,turn+1);
	tt[turn]=0;return 0;
}
int main(){
	
	int d,t;scanf("%d",&t); d=t;
	for(;d>0;d--){
		printf("#%d ",t-d+1);
		int i,j,tmp;ans = 0;
		memset(arr,0,sizeof(arr));
		for(i=1;i<=4;i++)for(j=1;j<=4;j++){
			scanf("%d ",&tmp);
			sprintf(&arr[i][j],"%d",tmp);
			//printf("%c",arr[i][j]);
		}
		for(i=1;i<=4;i++)for(j=1;j<=4;j++){
			memset(tt,0,sizeof(tt));
			dfs(i,j,0);
		}
		printf("%d\n",ans);
		mapp.clear();
	}
	return 0;
}