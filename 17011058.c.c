#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main () {
	srand (time(NULL));
	int tablo[4][4],a,y,o,p,i,j,A[100],n,m;
	char yon;
	int win=0;
	int tablo2[4][4],temp,fin=0,full=0;
	int score =0,highestscore=0,oldscore=0;
	for (i=0;i<4;i++){
		for(j=0;j<4;j++){
			tablo[i][j]=0;
		}
	}
	printf("                                         <<<Welcome to Game>>> \n\n\n");

	for (i=0;i<90;i++){
		A[i]=2;
}
	for (i=90;i<100;i++){
		A[i]=4;
	}

	a=rand()%4;
	y=rand()%4;                                         //ilk randomu atýyorum
	tablo[a][y]=A[rand()%100];

	do{
            if(score>highestscore)
            highestscore=score;
            
			for(i=0;i<4;i++){
            	for(j=0;j<4;j++){								//Burada ise tablonun 
            		if(tablo[i][j]!=0){
            		full+=1;
			}
				}
			}
			if(full==16){
				for(i=0;i<4;i++){								//dolu olup olmadýðýný kontrol edip
            	for(j=0;j<3;j++){
            		if((tablo[i][j])!=(tablo[i][j+1])){
            			fin++;
					}
			}
				}
			}														
			for(j=0;j<4;j++){									//oyunun bitip bitmemesi gerektiðine baktým
            	for(i=0;i<3;i++){
			if((tablo[i][j])!=(tablo[i+1][j]))
					fin++;
			}
		}
		if(fin==24)
		exit(0);
		fin=0;
			
		if(yon!='r' && full!=16){
            do {
			n=rand()%4;										//her tur ki gerekli random atýyorum
			m=rand()%4;
		}while(tablo[n][m]!=0);
	tablo[n][m]=A[rand()%100];
		}
	full=0;
	printf("                                                                               SCORE : %d\n",score);
	printf("                                                                               HIGHEST SCORE : %d\n",highestscore);
	printf("                                                                             Press x to restart \n ");
	printf("                                                                            Press e to finish the game\n");
	printf("                                                                             Press r for undo\n");
	printf("                                                                             << Use W A S D to play >> \n");
	for (i=0;i<4;i++){
		printf("                                       |");
		for(j=0;j<4;j++){
		if(tablo[i][j]==2048){						//oyun 2048e ulaþtýysa bitmesi için
				win=1;
			}
			if (tablo[i][j]==0){								
				printf("%4c|",' ');
		}
		else if((i==a&&j==y)||(i==n&&j==m))
		printf("%3d*|",tablo[i][j]);						//Tabloyu yazdýrýyorum
		else
		printf("%4d|",tablo[i][j]);
		}
		printf("\n\n");
	}
	if(win==1){
		printf("                                                  YOU WON");
		exit(0);
		
	}
	a=y=8;
	printf("\n\n\n");

	yon=getch();

	 //saga dogru toplama
	if(yon=='d'){ //77
	oldscore=score;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                temp=tablo[i][j];
                tablo2[i][j]=temp;
                tablo[i][j]=temp;
            }
        }

	for (i=0;i<4;i++){
		for(j=3;j>0;j--){
		 if(tablo[i][0]!=0 && tablo[i][1]!=0 && tablo[i][2]==0&&tablo[i][3]==0){
			 	tablo[i][3]=tablo[i][1];
			 	tablo[i][2]=tablo[i][0];
			 	tablo[i][1]=tablo[i][0]=0;
			 }
		else if(tablo[i][3]==0){
				tablo[i][3]=tablo[i][2];
				tablo[i][2]=tablo[i][1];
				tablo[i][1]=tablo[i][0];
				tablo[i][0]=0;
			}
			if (tablo[i][1]==0){
				tablo[i][1]=tablo[i][0];
				tablo[i][0]=0;
			}
			if (tablo[i][2]==0){
				tablo[i][2]=tablo[i][1];
				tablo[i][1]=tablo[i][0];
				tablo[i][0]=0;
			}

			 if (tablo[i][j]==tablo[i][j-1]){
				tablo[i][j]=tablo[i][j]+tablo[i][j-1];
				tablo[i][j-1]=0;
				score+=tablo[i][j];
			}

		}
		}
	}

	// sola kaydýrma
	else if(yon=='a') {//75
	oldscore=score;
            for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                temp=tablo[i][j];
                tablo2[i][j]=temp;
                tablo[i][j]=temp;
            }
        }

		for (i=0;i<4;i++){
			for(j=0;j<3;j++){
				if(tablo[i][3]!=0 && tablo[i][2]!=0 && tablo[i][1]==0 && tablo[i][0]==0){
			 	tablo[i][0]=tablo[i][2];
			 	tablo[i][1]=tablo[i][3];
			 	tablo[i][2]=tablo[i][3]=0;

			 }
			else if(tablo[i][0]==0){
				tablo[i][0]=tablo[i][1];
				tablo[i][1]=tablo[i][2];
				tablo[i][2]=tablo[i][3];
				tablo[i][3]=0;
			}
			 if (tablo[i][2]==0){
				tablo[i][2]=tablo[i][3];
				tablo[i][3]=0;
			}
			 if (tablo[i][1]==0){
				tablo[i][1]=tablo[i][2];
				tablo[i][2]=tablo[i][3];
				tablo[i][3]=0;
			}


			 if (tablo[i][j]==tablo[i][j+1]){
				tablo[i][j]=tablo[i][j]+tablo[i][j+1];
				tablo[i][j+1]=0;
				score+=tablo[i][j];
			}
		}
	}
}

	//yukarý kaydýrma
	else if(yon=='w'){//72
	oldscore=score;
            for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                temp=tablo[i][j];
                tablo2[i][j]=temp;
                tablo[i][j]=temp;
            }
        }

	for (j=0;j<4;j++){
			for(i=0;i<3;i++){
				if(tablo[3][j]!=0 && tablo[2][j]!=0 && tablo[1][j]==0 && tablo[0][j]==0){
			 	tablo[0][j]=tablo[2][j];
			 	tablo[1][j]=tablo[3][j];
			 	tablo[2][j]=tablo[3][j]=0;
			 }
			else if(tablo[0][j]==0){
				tablo[0][j]=tablo[1][j];
				tablo[1][j]=tablo[2][j];
				tablo[2][j]=tablo[3][j];
				tablo[3][j]=0;
			}
			if (tablo[2][j]==0){
				tablo[2][j]=tablo[3][j];
				tablo[3][j]=0;
			}
			 if (tablo[1][j]==0){
				tablo[1][j]=tablo[2][j];
				tablo[2][j]=tablo[3][j];
				tablo[3][j]=0;
			}

			 if (tablo[i][j]==tablo[i+1][j]){
				tablo[i][j]=tablo[i][j]+tablo[i+1][j];
				tablo[i+1][j]=0;
				score+=tablo[i][j];
			}
		}
	}
}

//	asagi kaydirma
	else if(yon=='s'){//80
	oldscore=score;
            for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                temp=tablo[i][j];
                tablo2[i][j]=temp;
                tablo[i][j]=temp;
            }
        }

	for (j=0;j<4;j++){
			for(i=3;i>0;i--){
				if(tablo[0][j]!=0 && tablo[1][j]!=0 && tablo[2][j]==0 && tablo[3][j]==0){
			 	tablo[3][j]=tablo[1][j];
			 	tablo[2][j]=tablo[0][j];
			 	tablo[0][j]=tablo[1][j]=0;
			 }
			else if(tablo[3][j]==0){
				tablo[3][j]=tablo[2][j];
				tablo[2][j]=tablo[1][j];
				tablo[1][j]=tablo[0][j];
				tablo[0][j]=0;
			}
			 if (tablo[1][j]==0){
				tablo[1][j]=tablo[0][j];
				tablo[0][j]=0;
			}
			 if (tablo[2][j]==0){
				tablo[2][j]=tablo[1][j];
				tablo[1][j]=tablo[0][j];
				tablo[0][j]=0;
			}


			 if (tablo[i][j]==tablo[i-1][j]){
				tablo[i][j]=tablo[i][j]+tablo[i-1][j];
				tablo[i-1][j]=0;
				score+=tablo[i][j];
			}
		}
	}
}

else if(yon=='x'){
        score=0;
	for (i=0;i<4;i++){							// restart yapýyor
		for(j=0;j<4;j++){
			tablo[i][j]=0;
		}
	}
	o=rand()%4;
	p=rand()%4;
	tablo[o][p]=A[rand()%100];
}
else if(yon=='e'){
	printf("                                              !! GAME OVER !!");
	exit(0);							//oyunu bitiriyor
}
else if(yon=='r'){
	score=oldscore;
        for(i=0;i<4;i++){				//undo
            for(j=0;j<4;j++){
                tablo[i][j]=tablo2[i][j];
            }
        }
}

}while(1);

	return 0;
}
