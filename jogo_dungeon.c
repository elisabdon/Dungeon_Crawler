#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include <pthread.h>

//DECLARANDO AS VARIÁVEIS
initconio();

char matriz1 [15][15];
char matriz2 [30][30];
char matriz3 [60][60];

  int fim1 = 0;
  int fim2 = 0;
  int fim3 = 0;
  
  char tecla1;
  char tecla2;
  char tecla3;
  
  int x=7;
  int y=7;
  
  int x2=15;
  int y2=15;
  
  int x3=15;
  int y3=15;
  
  char chave1='@';
  char chave2=' ';
  char chave3=' ';
  	
  char porta1='D';
  char porta2='D';
  char porta3='D';

  char botao2='O';
  char botao3='O';
  	
  char espinho2='#';
  char espinho3='#';
  	
  int eminemX2=18;
  int eminemY2=25;
	
  int lifes=3;
  int lixo;
  
  char teletransporte= '<';
  
  int npcX=18;
  int npcY=25;
  int npc2_Y3=47;
  int npc2_X3=43;
  int npc3_Y3=33;
  int npc3_X3=5;
  
  int E = 659;
  int FSharp = 739; 
  int GSharp = 830;
  int A = 880;
  int B = 988;
  int D = 1175;
  
  //TOCAR MUSICA DE INICIO 
  void playNote(int frequency, int duration) 
  {
    Beep(frequency, duration);
    Sleep(duration / 2);  
}
  
  
  //INICIO DA 1 FASE!
  void historinha()
{
	
	char historia[] =  "\n\t\t|--------------------------------------------------------------------------------------------------------------------------|"
					   "\n\t\t|   ERA UMA VEZ, EM UM MUNDO MUITO MUITO DISTANTE, ONDE A LUZ ERA FRACA, E A NEVOA PAERAVA UM LABIRINTO CHEIO DE SEGREDOS  |"
	                   "\n\t\t|GUARDADOS POR DIVERSAS PORTAS, BOTOES E INIMIGOS.                                                                         |"
	                   "\n\t\t|NINGUEM TINHA A CORAGEM, A FORCA E A PERSEVERANCA DE TENTAR DESVENDAR OS ENIGMAS GUARDADOS POR ESTE LOCAL.POREM, CERTO DIA|"
                       "\n\t\t|UM PEQUENO JOVEM ,CUJA A INTELIGENCIA ERA EXUBERANTE, SUA PERSEVERANCA DE INVEJAR E SUAS VESTES FLORIDAS UM ARRASO DECIDIU|"
					   "\n\t\t|ENFRENTAR SEUS MEDOS E SACIAR SUA CURIOSIDADE DE ADENTRAR OS LABIRINTOS. SEU NOME, MARCADO FUTURAMENTE PARA A HISTORIA ERA|"
					   "\n\t\t|                                               >TRIGOTO<.                                                                 |"
                       "\n\t\t|TRIGOTO ERA CONHECIDO PRINCIPALMENTE POR SUAS HABILIDADES TECNOLOGICAS, O JOVEM ERA MUITO HABIL QUANDO SE TRATAVA DE DES- |"
                       "\n\t\t|VENDAR DESAFIOS, FOI ENTAO, JUNTANDO SUAS HABILIDADES CERTO DIA, QUE TRIGOTO DECIDIU PARTIR EM UMA GRANDE AVENTURA PELOS  |"
					   "\n\t\t|LABIRINTOS,PARA DESCOBRIR EM FIM QUAL ERA O SEGREDO TAO ESTUPENDO QUE PRECISAVA SER GUARDADO POR TANTAS CHAVES ASSIM...   |"
					   "\n\t\t|--------------------------------------------------------------------------------------------------------------------------|"
                         
                        "\n\n\t\t\t\t\t    ------------------------------------------------------------"
	                    "  \n\t\t\t\t\t   /|AJUDE TRIGOTO EM SUA AVENTURA PELOS LABIRINTOS DE DUNGEON!|"
						"\n\t\t\t\t\t  /_|----------------------------------------------------------|";
	
	int h;
		    for (h = 0; historia[h] != '\0'; h++) {
		        printf("%c", historia[h]);
		        fflush(stdout);
		        usleep(15000);
		    }
		    printf("\n\n\n\t\t\t\t\t\t\t\t|A HISTORIA CONTEM 10 SEGUNDO|");
			Sleep(10000);
} 



void mapa1(char matriz1[15][15],int x, int y, char chave1, char porta1)
{	
	int i,j;	
		for(i = 0; i < 15; i++)
    	{
        	for(j = 0; j < 15; j++)
        	{	
        		if(i==y && j==x)
				{
					matriz1[i][j]='&';
				}
				else
				{
        			if(i==14 && j==7)
					{
						matriz1[i][j]=porta1;
					}
					else
					{ 
        				if(i==3 && j==7)
						{
							matriz1[i][j]=chave1;
						}
						else
						{			
   							if(i==0 || i==14)
							{
			 	 	 	 	 	matriz1[i][j]='*';printf("\n");
							}
							else
							{
								if(j==0 || j==14)
								{
									matriz1[i][j]='*';
								}
								else
								{					
									matriz1[i][j]=' ';
					    		}								
	    		        	}		
						}
					}
				}
        	}
    	}
    system("clear || cls");
    printf("\n\n\n\n\n\n\n\n");
    	for(i = 0; i < 15; i++)
    	{
    		printf("\t\t\t\t\t\t\t");
        	for(j = 0; j < 15; j++)
        	{
        		printf(" ");
            	printf("%c", matriz1[i][j]);
        	}
        	printf("\n");
    	}
}


//MOVIMENTAÇAÕ DO PERSONAGEM DA 1 FASE
void movimentacao1()
{
	char tecla1;
	tecla1 = getch();
    	switch(tecla1)
		{
			case 'w':
				if(y==1)
				{}
				else
				{
					y--;	
				}					
				break;
			case 's':
				if((y==13 && matriz1[14][7]=='D')&& (x!=7 || x==7))
				{}
				else
				{
					if(y==13 && x!=7)
					{}
					else
					{						
						y++;
						if(y==14 && x==7)
						{
							fim1=1;
						}
						else{}
					}
				}
				break;	
			case 'a':
				if(x==1)
				{}
				else
				{
					x--;
				}
				break;
			case 'd':
				if(x==13)
				{}
				else
				{
					x++;
				}
				break;
			case 'i':
				if(x==7 && y==3)
				{
						printf("\n\n\n");					
					    Sleep(20);
					   printf("\t\t\t\t\t\t#######  ####### #######  ####### ######  ####### ###     ##  #######\n");
					    Sleep(20);
						system("color 05");
					    printf("\t\t\t\t\t\t##    ## ##   ## ##    ## ##   ## ##   ## ##      ## #    ##  ##\n");
					    Sleep(20);
						system("color 04");
					    printf("\t\t\t\t\t\t##    ## ##   ## ##    ## ##   ## ######  ##      ##  #   ##  #######\n");
					    Sleep(20);
						system("color 07");
					    printf("\t\t\t\t\t\t######   ####### #######  ####### #    ## #####   ##   #  ##       ##\n");
					    Sleep(20);
						system("color 08");
					    printf("\t\t\t\t\t\t##       ##   ## ## ##    ##   ## ##   ## ##      ##    # ##       ##\n");
					    Sleep(20);
						system("color 09");
					   printf("\t\t\t\t\t\t##       ##   ## ##  ##   ##   ## ######  ####### ##     ###  #######\n");
					    Sleep(20);
						system("color 06");
						Sleep(900);
						system("cls");
    					system("color 07");
					chave1=' ';
					porta1='=';
				}
				else{}
				default:
				break;

		}
}

//INICIO DA 2 FASE!
void mapa2(char matriz2[30][30],int x2, int y2, char chave2, char porta2, char botao2, int eminemY2, int eminemX2, char espinho2) 
{
	int i,j;

	for(i = 0; i < 30; i++) 
	{
		for(j = 0; j < 30; j++) 
		{
			if (i==eminemY2 && j==eminemX2 ) 
			{
				matriz2[i][j]='E';
			}
			else 
			{
				if(i==y2 && j==x2) 
				{
					matriz2[i][j]='&';
				}
				else 
				{
					if(i==0 && j==15) 
					{
						matriz2[i][j]=porta2;
					}
					else 
					{
						if(i==27 && j==18) 
						{
							matriz2[i][j]=botao2;
						}
						else 
						{
							if (i==15 && j==15) 
							{
								matriz2[i][j]=chave2;
							}
							else 
							{

								if(i==0 || i==29) 
								{
									matriz2[i][j]='*';
									printf("\n");
								}
								else 
								{
									if(j==0 || j==29) 
									{
										matriz2[i][j]='*';
									}
									else 
									{
										matriz2[i][j]=' ';
									}
									
										//espinhos
										if(i==1 && j ==6 || i==1 && j ==7 || i==1 && j ==8 || i==1 && j ==9 || i==1 && j ==22 ||i==1 && j ==26)
										{
											matriz2[i][j] = '#';
										}
										if(i==2 && j ==3 || i==2 && j ==4 || i==2 && j ==5 || i==2 && j ==7 || i==2 && j ==7 ||i==2 && j ==26)
										{
											matriz2[i][j] = '#';
										}
								
										//labirinto
										if(i == 26 && j == 17 || i == 26 && j == 18 || i == 26 && j == 19)
										{
											matriz2[i][j] = '#';
										}
										if(i == 27 && j == 16 ||i == 27 && j == 17 || i == 27 && j == 19)
										{
											matriz2 [i][j] = '#';
										}
										if(i == 28 && j == 19)
										{
											matriz2[i][j] = '#';
										}
								}
							}
						}
					}
				}
			}
		}
	}
	system("clear || cls");
	printf("\n\n\n\n\n\n\n\n");
	for(i = 0; i < 30; i++) 
	{
		printf("\t\t\t\t\t\t\t");
		for(j = 0; j < 30; j++) 
		{
			printf(" ");
			printf("%c", matriz2[i][j]);
		}
		printf("\n");
	}
}
  //MOVIMENTAÇÃO DO INIMIGO
  void eminemMove2() 
{
	int eminem2;
	srand(time(NULL));
	eminem2 = 1 + (rand() % 4);
	
	switch (eminem2) 
	{
		case 1:
			if(eminemY2==1) 
			{} 
			else 
			{
				eminemY2--;
			}
			break;
		case 2:
			if(eminemY2==28) 
			{} 
			else 
			{
				eminemY2++;

			}
			break;
		case 3:
			if(eminemX2==1) 
			{} 
			else 
			{
				eminemX2--;
			}
			break;
		case 4:
			if(eminemX2==28) 
			{} 
			else 
			{
				eminemX2++;
			}
			break;
	}
}
  
  //MOVIMENTAÇÃO DO PERSONAGEM NA 2 FASE
  void movimentacao2() 
{
		char tecla2;
	tecla2 = getch();
	switch(tecla2)
	{
		case 'w':
			if((y2==1 && matriz2[0][15]=='D')&& (x2!=15 || x2==15)) 
			{} 
			else 
			{
				if(y2==1 && x2!=15) 
				{}
				else 
				{
					y2--;
					eminemMove2();
					if(y2==0 && x2==15) 
					{
						fim2=1;
					} 
					else {}
						if (x2==eminemX2 && y2==eminemY2) 
						{
							lifes--;
							x2=15;
							y2=15;
							chave2=' ';
							porta2='D';
							botao2='O';
							eminemX2=18;
							eminemY2=25;
								if (lifes==0) 
								{
									printf("\n\n");
								system("color 05");
								printf("\t\t\t\t\t\t########  ######## ###        ### #######     ######## ##          ## ####### ######\n");
								Sleep(300);
								system("color 07");
								printf("\t\t\t\t\t\t##        ##    ## ## #      # ## ##          ##    ##  ##        ##  ##      ##    ##\n");
								Sleep(300);
								system("color 08");
								printf("\t\t\t\t\t\t##   ###  ######## ##   #  #   ## #####       ##    ##    ##    ##    #####   ######\n");
								Sleep(300);
								system("color 09");
								printf("\t\t\t\t\t\t##    ##  ##    ## ##    ##    ## ##          ##    ##      ####      ##      ##  ##\n");
								Sleep(300);
								printf("\t\t\t\t\t\t########  ##    ## ##          ## #######     ########       ##       ####### ##   ##\n");
								Sleep(300);
								system("color 03");
								Sleep(900);
								printf("\n\t\t\t\t\t\tDigite 1 e pressione enter para continuar...");
								scanf("%d", &lixo);
								fim2=1;
								break;
								} 
								else {}
						} 
						else {}							
							//verificar o dano do espinho							
							if (matriz2[y2][x2] == espinho2) 
							{
								printf("\t\t\t\t\t\tVoce sofreu dano!\n");
								Sleep(900);
								lifes--;
								x2=15;
								y2=15;
								chave2=' ';
								porta2='D';
								botao2='O';
								eminemX2=18;
								eminemY2=25;
									if (lifes==0) 
									{
									printf("\n\n");
								system("color 05");
								printf("\t\t\t\t\t\t########  ######## ###        ### #######     ######## ##          ## ####### ######\n");
								Sleep(300);
								system("color 07");
								printf("\t\t\t\t\t\t##        ##    ## ## #      # ## ##          ##    ##  ##        ##  ##      ##    ##\n");
								Sleep(300);
								system("color 08");
								printf("\t\t\t\t\t\t##   ###  ######## ##   #  #   ## #####       ##    ##    ##    ##    #####   ######\n");
								Sleep(300);
								system("color 09");
								printf("\t\t\t\t\t\t##    ##  ##    ## ##    ##    ## ##          ##    ##      ####      ##      ##  ##\n");
								Sleep(300);
								printf("\t\t\t\t\t\t########  ##    ## ##          ## #######     ########       ##       ####### ##   ##\n");
								Sleep(300);
								system("color 03");
								Sleep(900);
								printf("\n\t\t\t\t\t\tDigite 1 e pressione enter para continuar...");
								scanf("%d", &lixo);
								fim2=1;
								break;
									} 
									else {}
							}
							
				}
			}
			break;
		case 's':
			if(y2==28) 
			{} 
			else 
			{
				y2++;
				eminemMove2();
					if (x2==eminemX2 && y2==eminemY2) 
					{
						lifes--;
						x2=15;
						y2=15;
						chave2=' ';
						porta2='D';
						botao2='O';
						eminemX2=18;
						eminemY2=25;
							if (lifes==0) 
							{
									printf("\n\n");
								system("color 05");
								printf("\t\t\t\t\t\t########  ######## ###        ### #######     ######## ##          ## ####### ######\n");
								Sleep(300);
								system("color 07");
								printf("\t\t\t\t\t\t##        ##    ## ## #      # ## ##          ##    ##  ##        ##  ##      ##    ##\n");
								Sleep(300);
								system("color 08");
								printf("\t\t\t\t\t\t##   ###  ######## ##   #  #   ## #####       ##    ##    ##    ##    #####   ######\n");
								Sleep(300);
								system("color 09");
								printf("\t\t\t\t\t\t##    ##  ##    ## ##    ##    ## ##          ##    ##      ####      ##      ##  ##\n");
								Sleep(300);
								printf("\t\t\t\t\t\t########  ##    ## ##          ## #######     ########       ##       ####### ##   ##\n");
								Sleep(300);
								system("color 03");
								Sleep(900);
								printf("\n\t\t\t\t\t\tDigite 1 e pressione enter para continuar...");
								scanf("%d", &lixo);
								fim2=1;
								break;
							} 
							else {}
					} 
					else {}					
					//verificar o dano do espinho
						if (matriz2[y2][x2] == espinho2) 
						{
							printf("\t\t\t\t\t\tVoce sofreu dano!\n");
							Sleep(900);
							lifes--;
							x2=15;
							y2=15;
							chave2=' ';
							porta2='D';
							botao2='O';
							eminemX2=18;
							eminemY2=25;
								if (lifes==0) 
								{
									printf("\n\n");
								system("color 05");
								printf("\t\t\t\t\t\t########  ######## ###        ### #######     ######## ##          ## ####### ######\n");
								Sleep(300);
								system("color 07");
								printf("\t\t\t\t\t\t##        ##    ## ## #      # ## ##          ##    ##  ##        ##  ##      ##    ##\n");
								Sleep(300);
								system("color 08");
								printf("\t\t\t\t\t\t##   ###  ######## ##   #  #   ## #####       ##    ##    ##    ##    #####   ######\n");
								Sleep(300);
								system("color 09");
								printf("\t\t\t\t\t\t##    ##  ##    ## ##    ##    ## ##          ##    ##      ####      ##      ##  ##\n");
								Sleep(300);
								printf("\t\t\t\t\t\t########  ##    ## ##          ## #######     ########       ##       ####### ##   ##\n");
								Sleep(300);
								system("color 03");
								Sleep(900);
								printf("\n\t\t\t\t\t\tDigite 1 e pressione enter para continuar...");
								scanf("%d", &lixo);
								fim2=1;
								break;
								} 
								else {}
						}
							
			
			break;
		case 'a':
			if(x2==1) 
			{} 
			else 
			{
				x2--;
				eminemMove2();
					if (x2==eminemX2 && y2==eminemY2) 
					{
						lifes--;
						x2=15;
						y2=15;
						chave2=' ';
						porta2='D';
						botao2='O';
						eminemX2=18;
						eminemY2=25;
							if (lifes==0) 
							{
									printf("\n\n");
								system("color 05");
								printf("\t\t\t\t\t\t########  ######## ###        ### #######     ######## ##          ## ####### ######\n");
								Sleep(300);
								system("color 07");
								printf("\t\t\t\t\t\t##        ##    ## ## #      # ## ##          ##    ##  ##        ##  ##      ##    ##\n");
								Sleep(300);
								system("color 08");
								printf("\t\t\t\t\t\t##   ###  ######## ##   #  #   ## #####       ##    ##    ##    ##    #####   ######\n");
								Sleep(300);
								system("color 09");
								printf("\t\t\t\t\t\t##    ##  ##    ## ##    ##    ## ##          ##    ##      ####      ##      ##  ##\n");
								Sleep(300);
								printf("\t\t\t\t\t\t########  ##    ## ##          ## #######     ########       ##       ####### ##   ##\n");
								Sleep(300);
								system("color 03");
								Sleep(900);
								printf("\n\t\t\t\t\t\tDigite 1 e pressione enter para continuar...");
								scanf("%d", &lixo);
								fim2=1;
								break;
							} 
							else {}
					} 
					else {}					
					//verificar o dano do espinho							
						if (matriz2[y2][x2] == espinho2) 
						{
							printf("\t\t\t\t\t\tVoce sofreu dano!\n");
							Sleep(900);
							lifes--;
							x2=15;
							y2=15;
							chave2=' ';
							porta2='D';
							botao2='O';
							eminemX2=18;
							eminemY2=25;
								if (lifes==0) 
								{
									printf("\n\n");
								system("color 05");
								printf("\t\t\t\t\t\t########  ######## ###        ### #######     ######## ##          ## ####### ######\n");
								Sleep(300);
								system("color 07");
								printf("\t\t\t\t\t\t##        ##    ## ## #      # ## ##          ##    ##  ##        ##  ##      ##    ##\n");
								Sleep(300);
								system("color 08");
								printf("\t\t\t\t\t\t##   ###  ######## ##   #  #   ## #####       ##    ##    ##    ##    #####   ######\n");
								Sleep(300);
								system("color 09");
								printf("\t\t\t\t\t\t##    ##  ##    ## ##    ##    ## ##          ##    ##      ####      ##      ##  ##\n");
								Sleep(300);
								printf("\t\t\t\t\t\t########  ##    ## ##          ## #######     ########       ##       ####### ##   ##\n");
								Sleep(300);
								system("color 03");
								Sleep(900);
								printf("\n\t\t\t\t\t\tDigite 1 e pressione enter para continuar...");
								scanf("%d", &lixo);
								fim2=1;
								break;
								} 
								else {}
						}	
			}							
			break;
		case 'd':
			if(x2==28) 
			{} 
			else 
			{
				x2++;
				eminemMove2();
					if (x2==eminemX2 && y2==eminemY2) 
					{
						lifes--;
						x2=15;
						y2=15;
						chave2=' ';
						porta2='D';
						botao2='O';
						eminemX2=18;
						eminemY2=25;
							if (lifes==0) 
							{
									printf("\n\n");
								system("color 05");
								printf("\t\t\t\t\t\t########  ######## ###        ### #######     ######## ##          ## ####### ######\n");
								Sleep(300);
								system("color 07");
								printf("\t\t\t\t\t\t##        ##    ## ## #      # ## ##          ##    ##  ##        ##  ##      ##    ##\n");
								Sleep(300);
								system("color 08");
								printf("\t\t\t\t\t\t##   ###  ######## ##   #  #   ## #####       ##    ##    ##    ##    #####   ######\n");
								Sleep(300);
								system("color 09");
								printf("\t\t\t\t\t\t##    ##  ##    ## ##    ##    ## ##          ##    ##      ####      ##      ##  ##\n");
								Sleep(300);
								printf("\t\t\t\t\t\t########  ##    ## ##          ## #######     ########       ##       ####### ##   ##\n");
								Sleep(300);
								system("color 03");
								Sleep(900);
								printf("\n\t\t\t\t\t\tDigite 1 e pressione enter para continuar...");
								scanf("%d", &lixo);
								fim2=1;
								break;
							} 
							else {}
					} 
					else {}						
						//verificar o dano do espinho			
						if (matriz2[y2][x2] == espinho2) 
						{
							printf("\t\t\t\t\t\tVoce sofreu dano!\n");
							Sleep(900);
							lifes--;
							x2=15;
							y2=15;
							chave2=' ';
							porta2='D';
							botao2='O';
							eminemX2=18;
							eminemY2=25;
								if (lifes==0) 
								{
									printf("\n\n");
								system("color 05");
								printf("\t\t\t\t\t\t########  ######## ###        ### #######     ######## ##          ## ####### ######\n");
								Sleep(300);
								system("color 07");
								printf("\t\t\t\t\t\t##        ##    ## ## #      # ## ##          ##    ##  ##        ##  ##      ##    ##\n");
								Sleep(300);
								system("color 08");
								printf("\t\t\t\t\t\t##   ###  ######## ##   #  #   ## #####       ##    ##    ##    ##    #####   ######\n");
								Sleep(300);
								system("color 09");
								printf("\t\t\t\t\t\t##    ##  ##    ## ##    ##    ## ##          ##    ##      ####      ##      ##  ##\n");
								Sleep(300);
								printf("\t\t\t\t\t\t########  ##    ## ##          ## #######     ########       ##       ####### ##   ##\n");
								Sleep(300);
								system("color 03");
								Sleep(900);
								printf("\n\t\t\t\t\t\tDigite 1 e pressione enter para continuar...");
								scanf("%d", &lixo);
								fim2=1;
								break;
								} 
								else {}
						}
							
						
			}
			break;
		case 'i':
			if(x2==18 && y2==27) 
			{
				chave2='@';
				botao2=' ';
			} 
			else {}
				if (x2==15 && y2==15 && chave2=='@') 
				{
						printf("\n\n\n");					
					    Sleep(20);
					   printf("\t\t\t\t\t\t######  ####### #######  ####### ######  ####### ###     ##  #######\n");
					    Sleep(20);
						system("color 05");
					    printf("\t\t\t\t\t\t##    ## ##   ## ##    ## ##   ## ##   ## ##      ## #    ##  ##\n");
					    Sleep(20);
						system("color 04");
					    printf("\t\t\t\t\t\t##    ## ##   ## ##    ## ##   ## ######  ##      ##  #   ##  #######\n");
					    Sleep(20);
						system("color 07");
					    printf("\t\t\t\t\t\t######   ####### #######  ####### #    ## #####   ##   #  ##       ##\n");
					    Sleep(20);
						system("color 08");
					    printf("\t\t\t\t\t\t##       ##   ## ## ##    ##   ## ##   ## ##      ##    # ##       ##\n");
					    Sleep(20);
						system("color 09");
					   printf("\t\t\t\t\t\t##       ##   ## ##  ##   ##   ## ######  ####### ##     ###  #######\n");
					    Sleep(20);
						system("color 06");
						Sleep(900);
						system("cls");
    					system("color 07");
					porta2='=';
					chave2=' ';
				}
				default:
				break;
			}
	}
}

  
  
  //INICIO JOGO 3!
void mapa3(char matriz3[60][60],int x3, int y3, char chave3, char porta3, char botao3, int npcY, int npcX, int npc2_Y3, int npc2_X3, int npc3_Y3, int npc3_X3, char espinho3) 
{
	int i,j;

	for(i = 0; i < 60; i++) 
	{
		for(j = 0; j < 60; j++) 
		{
			if (i==npcY && j==npcX || i == npc2_Y3 && j == npc2_X3 || i == npc3_Y3 && j == npc3_X3) 
			{
				matriz3[i][j]='E';
			}
			else 
			{
				if(i==3 && j==3) 
				{
					matriz3[i][j]='@';
				}
				else 
				{
					if(i==0 && j==15) 
					{
						matriz3[i][j]=porta3;
					}
					else 
					{
						if(i==27 && j==18) 
						{
							matriz3[i][j]=botao3;
						}
						else 
						{
							if (i==15 && j==15) 
							{
								matriz3[i][j]=chave3;
							}
							else 
							{

								if(i==0 || i==59) 
								{
									matriz3[i][j]='*';
									printf("\n");
								}
								else 
								{
									if(j==0 || j==59) 
									{
										matriz3[i][j]='*';
									}
									else 
									{
										matriz3[i][j]=' ';
									}
									
										//espinhos
										if(i==9 && j ==14 || i==8 && j ==14 || i==7 && j ==14 || i==4 && j ==14 || i==5 && j ==14 ||i==6 && j ==14 ||i==7 && j ==14 ||i==8 && j ==14 ||i==9 && j ==14 || i==10 && j==14||i==11 && j==14)
										{
											matriz3[i][j] = '#';
										}
										if(i==1 && j ==16 || i==2 && j ==16 || i==3 && j ==16 || i==4 && j ==16 || i==5 && j ==16 ||i==6 && j ==16||i==7 && j ==16||i==8 && j ==16||i==9 && j ==16)
										{
										matriz3[i][j] = '#';
										}
										if(i==11 && j==14||i==11 && j==15||i==11 && j==16||i==11 && j==17||i==11 && j==18||i==11 && j==19||i==11 && j==20||i==11 && j==21||i==11 && j==22||i==11 && j==23||i==11 && j==24||i==11 && j==25||i==11 && j==26||i==11 && j==27||i==11 && j==28||i==11 && j==29||i==11 && j==30||i==11 && j==31||i==11 && j==32||i==11 && j==33||i==11 && j==34||i==11 && j==35||i==11 && j==36||i==11 && j==37)
										{
											matriz3[i][j] = '#';
										}
										
										if(i==12 && j==37||i==13 && j==37||i==14 && j==37||i==15 && j==37||i==16 && j==37||i==17 && j==37||i==18 && j==37||i==19 && j==37||i==20 && j==37||i==21 && j==37||i==22 && j==37||i==23 && j==37||i==24 && j==37||i==25 && j==37||i==26 && j==37||i==27 && j==37||i==28 && j==37||i==29 && j==37||i==30 && j==37||i==31 && j==37||i==32 && j==37||i==33 && j==37||i==34 && j==37||i==35 && j==37||i==36 && j==37||i==37 && j==37||i==38 && j==37||i==39 && j==37||i==40 && j==37||i==41 && j==37||i==42 && j==37||i==43 && j==37||i==44 && j==37||i==45 && j==37||i==46 && j==37||i==47 && j==37||i==48 && j==37||i==49 && j==37)
										{
											matriz3[i][j] = '#';
										}
										
										if(i == 49 && j == 38 || i == 49 && j == 39 || i == 49 && j == 40)
										{
										matriz3[i][j] = '#';
										}
										
										if(i==9 && j==14||i==9 && j==16||i==9 && j==17||i==9 && j==18||i==9 && j==19||i==9 && j==20||i==9 && j==21||i==9 && j==22||i==9 && j==23||i==9 && j==24||i==9 && j==25||i==9 && j==26||i==9 && j==27||i==9 && j==28||i==9 && j==29||i==9 && j==30 || i==9 && j==31 || i==9 && j==32 || i==9 && j== 33|| i==9 && j==34||i==9 && j==35||i==9 && j==36||i==9 && j==37||i==9 && j==38||i==9 && j==39||i==9 && j==40)
										{
											matriz3[i][j] = '#';
										}
										
										if(i==9 && j==40||i==10 && j==40||i==11 && j==40||i==12 && j==40||i==13 && j==40||i==14 && j==40||i==15 && j==40||i==16 && j==40||i==17 && j==40||i==18 && j==40||i==19 && j==40||i==20 && j==40||i==21 && j==40||i==22 && j==40||i==23 && j==40||i==24 && j==40 || i==25 && j==40 || i==26 && j==40 || i==27 && j== 40)
										{
											matriz3[i][j] = '#';
										}
										
																
										if(i == 26 && j == 17 || i == 26 && j == 18 || i == 26 && j == 19)
										{
										matriz3[i][j] = '#';
										}
										if(i == 27 && j == 16 ||i == 27 && j == 17 || i == 27 && j == 19)
										{
										matriz3[i][j] = '#';
										}
										if(i == 28 && j == 19)
										{
											matriz3[i][j] = '#';
										}
										
										if(i==28 && j==40||i==29 && j== 40 ||i==30 && j== 40 ||i==31 && j== 40 ||i==32 && j== 40 ||i==33 && j== 40 ||i==34 && j== 40 ||i==35 && j== 40 ||i==36 && j== 40 ||i==37 && j== 40 ||i==38 && j== 40 ||i==39 && j== 40 ||i==40 && j== 40 ||i==41 && j== 40 ||i==42 && j== 40||i==43 && j== 40 || i==44 && j== 40 || i==45 && j== 40 || i==46 && j== 40)
										{
											matriz3[i][j] = '#';
										}
										
										if(i == 46 && j == 41 ||i == 46 && j == 42 || i == 46 && j == 43 || i == 46 && j == 44)
										{
										matriz3[i][j] = '#';
										}
										
										if(i == 47 && j == 44 ||i == 48 && j == 44 || i == 49 && j == 44 || i == 50 && j == 44|| i == 51 && j == 44 )
										{
										matriz3[i][j] = '#';
										}
										
										if(i == 51 && j == 43 ||i == 51 && j == 42 || i == 51 && j == 41 || i == 51 && j == 40|| i == 51 && j == 39 || i == 51 && j == 38 || i == 51 && j == 37 || i == 51 && j == 36 || i == 51 && j == 35 || i == 51 && j ==34)
										{
										matriz3[i][j] = '#';
										}
										
										if( i == 50 && j ==34|| i == 49 && j ==34|| i == 48 && j ==34|| i == 47 && j ==34|| i == 46 && j ==34|| i == 45 && j ==34|| i == 44 && j ==34|| i == 43 && j ==34|| i == 42 && j ==34|| i == 41 && j ==34|| i == 40 && j ==34|| i == 39 && j ==34|| i == 38 && j ==34|| i == 37 && j ==34|| i == 36 && j ==34|| i == 35 && j ==34|| i == 34 && j ==34)
										{
											matriz3[i][j] = '#';
										}
										
										if( i == 33 && j ==34|| i == 32 && j ==34|| i == 31 && j ==34|| i == 30 && j ==34|| i == 29 && j ==34|| i == 28 && j ==34|| i == 27 && j ==34|| i == 26 && j ==34|| i == 25 && j ==34 || i == 24 && j == 34 || i == 23 && j == 34 || i == 22 && j == 34)
										{
											matriz3[i][j] = '#';
										}
										
										if(i == 14 && j == 32 ||i == 14 && j == 33 || i == 14 && j == 34 || i == 14 && j == 35|| i == 14 && j == 36)
										{
										matriz3[i][j] = '#';
										}
										
										if(i == 16 && j == 15 ||i == 16 && j == 16||i == 16 && j == 17 ||i == 16 && j == 18 ||i == 16 && j == 19 ||i == 16 && j == 20||i == 16 && j == 21||i == 16 && j == 22||i == 16 && j == 23||i == 16 && j == 24 ||i == 16 && j == 25 ||i == 16 && j == 26)
										{
										matriz3[i][j] = '#';
										}
										
										if(i == 14 && j == 15 || i == 14 && j == 17||i == 14 && j == 18||i == 14 && j == 19||i == 14 && j == 20||i == 14 && j == 21||i == 14 && j == 22||i == 14 && j == 23||i == 14 && j == 24||i == 14 && j == 25||i == 14 && j == 26||i == 14 && j ==27 ||i == 14 && j == 28||i == 14 && j == 29||i == 14 && j == 30||i == 14 && j == 31 )
										{
											matriz3[i][j] = '#';
										}
										
										if(i == 17 && j == 26 ||i == 18 && j == 26||i == 19 && j == 26||i == 20 && j == 26||i == 21 && j == 26||i == 22 && j == 26)
										{
											matriz3[i][j] = '#';
										}
										
										if(i == 22 && j == 27 ||i == 22 && j == 28||i == 22 && j == 29||i == 22 && j == 30||i == 22 && j == 31||i == 22 && j == 32 || i == 22 && j == 33)
										{
											matriz3[i][j] = '#';
										}
										if(i == 49 && j == 43 || i == 35 && j == 6)
										{
											matriz3[i][j] = '<';
										}
										
										if(i == 32 && j == 6|| i == 32 && j == 7||i == 32 && j == 8||i == 32 && j == 9||i == 32 && j == 11||i == 32 && j == 7||i == 32 && j == 9||i == 32 && j == 12||i == 32 && j == 20||i == 32 && j == 22)
										{
											matriz3[i][j] = '#';
										}
										
										if(i == 37 && j == 6|| i == 37 && j == 7||i == 37 && j == 8||i == 37 && j == 9||i == 37 && j == 10||i == 37 && j == 5||i == 37 && j == 4||i == 37 && j == 3||i == 37 && j == 2||i == 37 && j == 1)
										{
											matriz3[i][j] = '#';
										}
										
										if(i == 37 && j == 11|| i == 33 && j == 11||i == 34 && j == 11||i == 35 && j == 11||i == 36 && j == 11)
										{
											matriz3[i][j] = '#';
										}



								}
							}
						}
					}
				}
			}
		}
	}
	system("clear || cls");
	printf("\n\n\n\n\n\n\n\n");
	for(i = 0; i < 60; i++) 
	{
		printf("\t\t\t\t\t\t\t");
		for(j = 0; j < 60; j++) 
		{
			printf(" ");
			printf("%c", matriz3[i][j]);
		}
		printf("\n");
	}
}

//MOVIMENTAÇÃO DO INIMIGO DA 3 FASE
void npcMove() 
{
	int npc, npc2, npc3;
	srand(time(NULL));
	npc = 1 + (rand() % 4);
	npc2 = 1 + (rand() % 4);
	npc3 = 1 + (rand() % 4);
	
	switch (npc) 
	{
		case 1:
			if(npcY==1) 
			{} 
			else 
			{
				npcY--;
			}
			break;
		case 2:
			if(npcY==58) 
			{} 
			else 
			{
				npcY++;

			}
			break;
		case 3:
			if(npcX==1) 
			{} 
			else 
			{
				npcX--;
			}
			break;
		case 4:
			if(npcX==58) 
			{} 
			else 
			{
				npcX++;
			}
			break;
	} 
	
	switch (npc2) 
	{
		case 1:
			if(npc2_Y3==1) 
			{} 
			else 
			{
				npc2_Y3--;
			}
			break;
		case 2:
			if(npc2_Y3==58) 
			{} 
			else 
			{
				npc2_Y3++;

			}
			break;
		case 3:
			if(npc2_X3==1) 
			{} 
			else 
			{
				npc2_X3--;
			}
			break;
		case 4:
			if(npc2_X3==58) 
			{} 
			else 
			{
				npc2_X3++;
			}
			break;
	}
	
	switch (npc3) 
	{
		case 1:
			if(npc3_Y3==1) 
			{} 
			else 
			{
				npc3_Y3--;
			}
			break;
		case 2:
			if(npc3_Y3==4) 
			{} 
			else 
			{
				npc3_Y3++;

			}
			break;
		case 3:
			if(npc3_X3==1) 
			{} 
			else 
			{
				npc3_X3--;
			}
			break;
		case 4:
			if(npc3_X3==10) 
			{} 
			else 
			{
				npc3_X3++;
			}
			break;
	}
}

//MOVIMENTAÇÃO DO PERSONAGEM DAA 3 FASE
void movimentacao3() 
{
		char tecla3;
	tecla3 = getch();
	switch(tecla3) 
	{
		case 'w':
			if((y3==1 && matriz3[0][15]=='D')&& (x3!=15 || x3==15) && (y3==1 && matriz3[0][13]=='D')&& (x3!=13 || x3==13) && (y3==1 && matriz3[0][12]=='D')&& (x3!=12 || x3==12) && (y3==1 && matriz3[0][11]=='D')&& (x3!=11 || x3==11)) 
			{} 
			else 
			{
				if((y3==1 && x3!=15) && (y3==1 && x3!=13) && (y3==1 && x3!=12) && (y3==1 && x3!=11)) 
				{}
				else 
				{
					y3--;
					npcMove();
						if(y3==0 && x3==15) 
						{
						system("cls");
						char final[] = "\n\t\t\t\t\t\t\t\t\t >>| PARABENS!! |<<"
						"\n\t\t\t\t|TRIGOTO, COM SUA AJUDA, CONSEGUIU DESVENDAR O GRANDE SEGREDO QUE ESTAVA ESCONDIDO NO LABIRINTO!                               |"
						"\n\n\t\t  |O SEGREDO, MUDOU A VIDA DE TIROGO PARA SEMPRE! ELE, AO ADENTRAR NESTA AVENTURA, NAO SABIA QUE SE TRATAVA DE ALGO TAO GRANDIOSO|"
						"\n\t\t    |ASSIM!!                                                                                                                       |"     
						"\n\n\t\t  |TRIGOTO, MESMO SENDO MUITO INTELIGENTE E HABILIDOSO, NUNCA IMAGINOU QUE PUDESSE ENCONTRAR E REINVIDICAR A POSSE DAS TERRAS DE |"
						"\n\t\t    |>SPACEU<, TERRA MAGICA ONDE ELE DEDICOU SUA VIDA PARA APRENDER TUDO O QUE PODIA COM OS MAGOS QUE ALI VIVIAM                   |"
						"\n\t\t    |AGORA, SENDO O DONO DESSAS TERRAS, TRIGOTO DEDICA O RESTANTE DE SUA VIDA PARA ENSINAR JOVENS SPACEUANOS SOBRE FORCA           |"
						"\n\t\t    |DEDICACAO, PACIENCIA E CLARO, TECNOLOGIA!!                                                                                    |"
						"\n\n\t\t\t===============================================================================================================================";
						
						int f;
								    for (f = 0; final[f] != '\0'; f++) {
								        printf("%c", final[f]);
								        fflush(stdout);
								        usleep(20000);
						               	}
							    printf("\n\t\t\t\t\t\t*  |   *   |   |\n");
							    Sleep(10);
							    printf("\n\t\t\t\t\t\t|    |   *  |  *\n");
							    Sleep(10);
							    printf("\n\t\t\t\t\t\t  *      |\n");
							    Sleep(10);
							    printf("\n\t\t\t\t\t\t  |   |       |\n");
							    Sleep(10);
							    printf("\n\t\t\t\t\t\t|        |	*\n");
							    Sleep(10);
							    printf("\n\t\t\t\t\t\t #      #      #\n");
							    Sleep(10);
							    printf("\n\t\t\t\t\t\t  ##   ###   ##\n");
							    Sleep(10);
							    printf("\n\t\t\t\t\t\t   ###########\n");
							    Sleep(10);
							    printf("\n\t\t\t\t\t\t   ###########\n");
							    Sleep(10);
							    printf("\n\t\t\t\t\t\t (=============)\n");
							    Sleep(10);
							    printf("\n\n\n");
			   
						 printf("\n\t\t\t\t\t|A FINALIZACAO CONTEM 10 SEGUNDOS, ESPERE PARA VOLTAR PARA O MENU PRINCIPAL!|");
						 Sleep(10000);
						 
						fim3=1;
						} 
						else {}
							if (x3==npcX && y3==npcY || x3==npc2_X3 && y3==npc2_Y3 || x3==npc3_X3 && y3==npc3_Y3) 
							{
							lifes--;
							x3=3;
							y3=4;
							chave3=' ';
							porta3='D';
							botao3='O';
							npcX=18;
							npcY=25;
							npc2_X3=43;
							npc2_Y3=47;
							npc3_Y3=33;
                            npc3_X3=5;
								if (lifes==0) 
								{
									printf("\n\n");
								system("color 05");
								printf("\t\t\t\t\t\t########  ######## ###        ### #######     ######## ##          ## ####### ######\n");
								Sleep(300);
								system("color 07");
								printf("\t\t\t\t\t\t##        ##    ## ## #      # ## ##          ##    ##  ##        ##  ##      ##    ##\n");
								Sleep(300);
								system("color 08");
								printf("\t\t\t\t\t\t##   ###  ######## ##   #  #   ## #####       ##    ##    ##    ##    #####   ######\n");
								Sleep(300);
								system("color 09");
								printf("\t\t\t\t\t\t##    ##  ##    ## ##    ##    ## ##          ##    ##      ####      ##      ##  ##\n");
								Sleep(300);
								printf("\t\t\t\t\t\t########  ##    ## ##          ## #######     ########       ##       ####### ##   ##\n");
								Sleep(300);
								system("color 03");
								Sleep(900);
								printf("\n\t\t\t\t\t\tDigite 1 e pressione enter para continuar...");
								scanf("%d", &lixo);
								fim3=1;
								break;
								} 
								else {}
							} 
							else {}
							
							//verificar o dano do espinho
							
							if (matriz3[y3][x3] == espinho3) 
							{
								printf("\t\t\t\t\t\tVoce sofreu dano!\n");
								Sleep(900);
								lifes--;
								x3=15;
								y3=15;
								chave3=' ';
								porta3='D';
								botao3='O';
								npcX=18;
								npcY=25;
								npc2_X3=43;
							    npc2_Y3=47;
							    npc3_Y3=33;
                                npc3_X3=5;
								if (lifes==0) 
								{
									printf("\n\n");
								system("color 05");
								printf("\t\t\t\t\t\t########  ######## ###        ### #######     ######## ##          ## ####### ######\n");
								Sleep(300);
								system("color 07");
								printf("\t\t\t\t\t\t##        ##    ## ## #      # ## ##          ##    ##  ##        ##  ##      ##    ##\n");
								Sleep(300);
								system("color 08");
								printf("\t\t\t\t\t\t##   ###  ######## ##   #  #   ## #####       ##    ##    ##    ##    #####   ######\n");
								Sleep(300);
								system("color 09");
								printf("\t\t\t\t\t\t##    ##  ##    ## ##    ##    ## ##          ##    ##      ####      ##      ##  ##\n");
								Sleep(300);
								printf("\t\t\t\t\t\t########  ##    ## ##          ## #######     ########       ##       ####### ##   ##\n");
								Sleep(300);
								system("color 03");
								Sleep(900);
								printf("\n\t\t\t\t\t\tDigite 1 e pressione enter para continuar...");
								scanf("%d", &lixo);
								fim3=1;
								break;
								} 
								else {}
							}
							
				}
			}
			break;
		case 's':
			if(y3==58) 
			{} 
			else 
			{
				y3++;
				npcMove();
					if (x3==npcX && y3==npcY || x3==npc2_X3 && y3==npc2_Y3) 
					{
					lifes--;
					x3=3;
					y3=4;
					chave3=' ';
					porta3='D';
					botao3='O';
					npcX=18;
					npcY=25;
					npc2_X3=43;
					npc2_Y3=47;
					npc3_Y3=33;
                    npc3_X3=5;
						if (lifes==0) 
						{
									printf("\n\n");
								system("color 05");
								printf("\t\t\t\t\t\t########  ######## ###        ### #######     ######## ##          ## ####### ######\n");
								Sleep(300);
								system("color 07");
								printf("\t\t\t\t\t\t##        ##    ## ## #      # ## ##          ##    ##  ##        ##  ##      ##    ##\n");
								Sleep(300);
								system("color 08");
								printf("\t\t\t\t\t\t##   ###  ######## ##   #  #   ## #####       ##    ##    ##    ##    #####   ######\n");
								Sleep(300);
								system("color 09");
								printf("\t\t\t\t\t\t##    ##  ##    ## ##    ##    ## ##          ##    ##      ####      ##      ##  ##\n");
								Sleep(300);
								printf("\t\t\t\t\t\t########  ##    ## ##          ## #######     ########       ##       ####### ##   ##\n");
								Sleep(300);
								system("color 03");
								Sleep(900);
								printf("\n\t\t\t\t\t\tDigite 1 e pressione enter para continuar...");
								scanf("%d", &lixo);
								fim3=1;
								break;
						} 
						else {}
					} 
					else {}
					
					//verificar o dano do espinho
							
							if (matriz3[y3][x3] == espinho3) 
							{
								printf("\t\t\t\t\t\tVoce sofreu dano!\n");
								Sleep(900);
								lifes--;
								x3=15;
								y3=15;
								chave3=' ';
								porta3='D';
								botao3='O';
								npcX=18;
								npcY=25;
								npc2_X3=43;
							    npc2_Y3=47;
							    npc3_Y3=33;
                                npc3_X3=5;
								if (lifes==0) 
								{
									printf("\n\n");
								system("color 05");
								printf("\t\t\t\t\t\t########  ######## ###        ### #######     ######## ##          ## ####### ######\n");
								Sleep(300);
								system("color 07");
								printf("\t\t\t\t\t\t##        ##    ## ## #      # ## ##          ##    ##  ##        ##  ##      ##    ##\n");
								Sleep(300);
								system("color 08");
								printf("\t\t\t\t\t\t##   ###  ######## ##   #  #   ## #####       ##    ##    ##    ##    #####   ######\n");
								Sleep(300);
								system("color 09");
								printf("\t\t\t\t\t\t##    ##  ##    ## ##    ##    ## ##          ##    ##      ####      ##      ##  ##\n");
								Sleep(300);
								printf("\t\t\t\t\t\t########  ##    ## ##          ## #######     ########       ##       ####### ##   ##\n");
								Sleep(300);
								system("color 03");
								Sleep(900);
								printf("\n\t\t\t\t\t\tDigite 1 e pressione enter para continuar...");
								scanf("%d", &lixo);;
								fim3=1;
								} 
								else {}
							}
							
			}
			break;
		case 'a':
			if(x3==1) 
			{} 
			else 
			{
				x3--;
				npcMove();
					if (x3==npcX && y3==npcY || x3==npc2_X3 && y3==npc2_Y3) 
					{
					lifes--;
					x3=3;
					y3=4;
					chave3=' ';
					porta3='D';
					botao3='O';
					npcX=18;
					npcY=25;
					npc2_X3=43;
					npc2_Y3=47;
					npc3_Y3=33;
                    npc3_X3=5;
						if (lifes==0) 
						{
							printf("\n\n");
					system("color 05");
									printf("\n\n");
								system("color 05");
								printf("\t\t\t\t\t\t########  ######## ###        ### #######     ######## ##          ## ####### ######\n");
								Sleep(300);
								system("color 07");
								printf("\t\t\t\t\t\t##        ##    ## ## #      # ## ##          ##    ##  ##        ##  ##      ##    ##\n");
								Sleep(300);
								system("color 08");
								printf("\t\t\t\t\t\t##   ###  ######## ##   #  #   ## #####       ##    ##    ##    ##    #####   ######\n");
								Sleep(300);
								system("color 09");
								printf("\t\t\t\t\t\t##    ##  ##    ## ##    ##    ## ##          ##    ##      ####      ##      ##  ##\n");
								Sleep(300);
								printf("\t\t\t\t\t\t########  ##    ## ##          ## #######     ########       ##       ####### ##   ##\n");
								Sleep(300);
								system("color 03");
								Sleep(900);
								printf("\n\t\t\t\t\t\tDigite 1 e pressione enter para continuar...");
								scanf("%d", &lixo);
								fim3=1;
						} 
						else {}
					} 
					else {}
					
					//verificar o dano do espinho
							
							if (matriz3[y3][x3] == espinho3) 
							{
								printf("\t\t\t\t\t\tVoce sofreu dano!\n");
								Sleep(900);
								lifes--;
								x3=15;
								y3=15;
								chave3=' ';
								porta3='D';
								botao3='O';
								npcX=18;
								npcY=25;
								npc2_X3=43;
							    npc2_Y3=47;
							    npc3_Y3=33;
                                npc3_X3=5;
								if (lifes==0) 
								{
									printf("\n\n");
								system("color 05");
								printf("\t\t\t\t\t\t########  ######## ###        ### #######     ######## ##          ## ####### ######\n");
								Sleep(300);
								system("color 07");
								printf("\t\t\t\t\t\t##        ##    ## ## #      # ## ##          ##    ##  ##        ##  ##      ##    ##\n");
								Sleep(300);
								system("color 08");
								printf("\t\t\t\t\t\t##   ###  ######## ##   #  #   ## #####       ##    ##    ##    ##    #####   ######\n");
								Sleep(300);
								system("color 09");
								printf("\t\t\t\t\t\t##    ##  ##    ## ##    ##    ## ##          ##    ##      ####      ##      ##  ##\n");
								Sleep(300);
								printf("\t\t\t\t\t\t########  ##    ## ##          ## #######     ########       ##       ####### ##   ##\n");
								Sleep(300);
								system("color 03");
								Sleep(900);
								printf("\n\t\t\t\t\t\tDigite 1 e pressione enter para continuar...");
								scanf("%d", &lixo);
								fim3=1;
								} 
								else {}
							}
							
					
				break;
			case 'd':
				if(x3==58) 
				{} 
				else 
				{
					x3++;
					npcMove();
						if (x3==npcX && y3==npcY || x3==npc2_X3 && y3==npc2_Y3) 
						{
						lifes--;
						x3=3;
						y3=4;
						chave3=' ';
						porta3='D';
						botao3='O';
						npcX=18;
						npcY=25;
						npc2_X3=43;
					    npc2_Y3=47;
					    npc3_Y3=33;
                        npc3_X3=5;
							if (lifes==0) 
							{
									printf("\n\n");
								system("color 05");
								printf("\t\t\t\t\t\t########  ######## ###        ### #######     ######## ##          ## ####### ######\n");
								Sleep(300);
								system("color 07");
								printf("\t\t\t\t\t\t##        ##    ## ## #      # ## ##          ##    ##  ##        ##  ##      ##    ##\n");
								Sleep(300);
								system("color 08");
								printf("\t\t\t\t\t\t##   ###  ######## ##   #  #   ## #####       ##    ##    ##    ##    #####   ######\n");
								Sleep(300);
								system("color 09");
								printf("\t\t\t\t\t\t##    ##  ##    ## ##    ##    ## ##          ##    ##      ####      ##      ##  ##\n");
								Sleep(300);
								printf("\t\t\t\t\t\t########  ##    ## ##          ## #######     ########       ##       ####### ##   ##\n");
								Sleep(300);
								system("color 03");
								Sleep(900);
								printf("\n\t\t\t\t\t\tDigite 1 e pressione enter para continuar...");
								scanf("%d", &lixo);
								fim3=1;
							} 
							else {}
						} 
						else {}
						
						//verificar o dano do espinho
							
							if (matriz3[y3][x3] == espinho3) 
							{
								printf("\t\t\t\t\t\tVoce sofreu dano!\n");
								Sleep(900);
								lifes--;
								x3=15;
								y3=15;
							
								chave3=' ';
								porta3='D';
								botao3='O';
								npcX=18;
								npcY=25;
								npc2_X3=43;
							    npc2_Y3=47;
							    npc3_Y3=33;
                                npc3_X3=5;
								if (lifes==0) 
								{
									printf("\n\n");
								system("color 05");
								printf("\t\t\t\t\t\t########  ######## ###        ### #######     ######## ##          ## ####### ######\n");
								Sleep(300);
								system("color 07");
								printf("\t\t\t\t\t\t##        ##    ## ## #      # ## ##          ##    ##  ##        ##  ##      ##    ##\n");
								Sleep(300);
								system("color 08");
								printf("\t\t\t\t\t\t##   ###  ######## ##   #  #   ## #####       ##    ##    ##    ##    #####   ######\n");
								Sleep(300);
								system("color 09");
								printf("\t\t\t\t\t\t##    ##  ##    ## ##    ##    ## ##          ##    ##      ####      ##      ##  ##\n");
								Sleep(300);
								printf("\t\t\t\t\t\t########  ##    ## ##          ## #######     ########       ##       ####### ##   ##\n");
								Sleep(300);
								system("color 03");
								Sleep(900);
								printf("\n\t\t\t\t\t\tDigite 1 e pressione enter para continuar...");
								scanf("%d", &lixo);
								fim3=1;
								} 
								else {}
							}
							
						
				}
				break;
			case 'i':
				if(x3==18 && y3==27) 
				{
					chave3='&';
					botao3=' ';
					teletransporte= '<';
				} 
				else {}
					if (x3==15 && y3==15 && chave3=='&') 
					{
					porta3='=';
					chave3=' ';
					matriz3[0][13]='*';
					matriz3[0][12]='*';
					matriz3[0][11]='*';
					}	
					if (x3==6 && y3==35 && teletransporte=='<')
					{
						printf("\n\n\n");
						printf("\t\t\t\t\t\t########  ######   ##     ######  #######  ######     #######  ###     ##  #######   ######   #######  #####   ########  ######\n");
						Sleep(300);
						system("color 01");
						printf("\t\t\t\t\t\t   ##     ##       ##     ##        ##     ##   ##    ##   ##  ## #    ##  ##        ##   ##  ##   ##  ##   ##    ##     ##\n");
						Sleep(300);
						system("color 02");
						printf("\t\t\t\t\t\t   ##     #####    ##     #####     ##     ######     #######  ##  #   ##  #######   ######   ##   ##  ######     ##     #####\n");
						Sleep(300);
						system("color 03");
						printf("\t\t\t\t\t\t   ##     ##       ##     ##        ##     ##  ##     ##   ##  ##   #  ##       ##   ##       ##   ##  ##         ##     ##\n");
						Sleep(300);
						system("color 04");
						printf("\t\t\t\t\t\t   ##     ######   #####  ######    ##     ##   ##    ##   ##  ##    ###   #######   ##       #######  ##         ##     ######\n");
						Sleep(300);
						system("color 05");
						
						 printf("\n\n\n");  
						printf("\t\t\t\t\t\t    #######  ########  ##  ##       ##  #######  ######    #######\n");
						Sleep(300);
						system("color 06");
						printf("\t\t\t\t\t\t    ##   ##     ##     ##   ##     ##   ##   ##  ##    ##  ##   ##\n");
						Sleep(300);
						system("color 08");
						printf("\t\t\t\t\t\t    #######     ##     ##    ##   ##    #######  ##    ##  ##   ##\n");
						Sleep(300);
						system("color 09");
						printf("\t\t\t\t\t\t    ##   ##     ##     ##     ## ##     ##   ##  ##    ##  ##   ##\n");
						Sleep(300);
						system("color 0A");
						printf("\t\t\t\t\t\t    ##   ##     ##     ##      ###      ##   ##  ######    #######\n");
						Sleep(300);
						system("color 07");

						 x3 = 43;
                         y3 = 49;
					}
					
					if (x3==43 && y3==49 && teletransporte=='<')
					{
				
					}
			default:
				break;
			}
	}
}
  
  
  void Jogo()
{
	while(fim1==0) //dinamica da fase1
	{	
		
		mapa1(matriz1,x,y,chave1,porta1);
	   	
		movimentacao1();	
    	
	}
	
	while(fim2==0) //dinamica da fase2
	{
		mapa2(matriz2,x2,y2,chave2,porta2,botao2,eminemY2,eminemX2,espinho2);

		movimentacao2();
	}
	
	while(fim3==0) //dinamica da fase3
	{
		mapa3(matriz3,x3,y3,chave3,porta3,botao3,npcY,npcX,npc2_Y3,npc2_X3,npc3_Y3,npc3_X3,espinho3);

		movimentacao3();
	}
}
void playSound(int frequency, int duration)
{
    Beep(frequency, duration);
}
//VOID PARA TOCAR A MUSICA DO TUTORIAL
void* playSonicMelody(void* arg)
{
   int C = 261;
    int D = 293;
    int E = 329;
    int F = 349;
    int G = 392;
    int A = 440;
    int B = 493;

    // Duração das notas em milissegundos
    int quarterNote = 250;
    int eighthNote = 125;

    // Melodia de "Resurrections" - Celeste
    for (int i = 0; i < 2; i++) {
    playSound(A, quarterNote);
    playSound(E, quarterNote);
    playSound(D, quarterNote);
    playSound(C, quarterNote);
    playSound(B, quarterNote);
    playSound(A, quarterNote);
    playSound(G, quarterNote);
    playSound(E, quarterNote);
    playSound(F, quarterNote);
    playSound(D, quarterNote);
    playSound(C, quarterNote);
    playSound(B, quarterNote);
    playSound(A, quarterNote);
    playSound(G, quarterNote);
    playSound(F, quarterNote);
    playSound(E, quarterNote);
    playSound(D, quarterNote);
    playSound(E, eighthNote);
    playSound(F, eighthNote);
    playSound(G, eighthNote);
    playSound(A, eighthNote);
    playSound(A, quarterNote);
    playSound(G, quarterNote);
    playSound(F, quarterNote);
    playSound(E, quarterNote);
    playSound(D, quarterNote);
    playSound(C, quarterNote);
    playSound(B, quarterNote);
    playSound(A, quarterNote);
    playSound(G, quarterNote);
    playSound(F, quarterNote);
    playSound(G, eighthNote);
    playSound(F, eighthNote);
    playSound(E, eighthNote);
    playSound(D, eighthNote);
    playSound(D, quarterNote);
    }

    pthread_exit(NULL);
}


// Função para reproduzir o som usando o comando Beep
void playSound1(int frequency, int duration)
{
    Beep(frequency, duration);
}
  
  // MENU PRINCIPAL
int main()
{
	setlocale(LC_ALL, "Portuguese");
	int escolha_menu;
	int lixo;

    // Frequências das notas musicais introdução
    int A = 440;
    int Bb = 466;
    int B = 494;
    int C = 523;
    int Db = 554;
    int D = 587;
    int Eb = 622;
    int E = 659;
    int F = 698;
    int Gb = 740;
    int G = 784;
    int Ab = 830;

    // Duração das notas em milissegundos
    int quarterNote = 450;
    int eighthNote = 350;

	while(escolha_menu != 3)
	{

		system("cls");
    	printf("\n\n\n");
    	system("color 06");
        printf("\t\t\t    #######   #######  ###        ###        ##          ##  ##  ###      ##  #######    ########\n");
		playSound1(G, quarterNote);
		playSound1(G, quarterNote);
        system("color 05");
        printf("\t\t\t    ##    ##  ##       ## #      # ##         ##        ##   ##  ## #     ##  ##     ##  ##    ##\n");
        playSound1(G, quarterNote);
        playSound1(Eb, 2 * quarterNote); 
        system("color 07");
        printf("\t\t\t    ##    ##  ##       ##  #    #  ##          ##      ##    ##  ##  #    ##  ##     ##  ##    ##\n");
        playSound1(C, quarterNote);
        playSound1(G, quarterNote); 
        system("color 08");
        printf("\t\t\t    #######   ####     ##   #  #   ##   #####   ##    ##     ##  ##   #   ##  ##     ##  ##    ##\n");
        playSound1(Eb, 2 * quarterNote);
        playSound1(C, quarterNote);
        system("color 09");
        printf("\t\t\t    ##    ##  ##       ##    ##    ##   #####    ##  ##      ##  ##    #  ##  ##     ##  ##    ##\n");
        playSound1(G, quarterNote);
        playSound1(Eb, 2 * quarterNote);
        printf("\t\t\t    ##    ##  ##       ##    ##    ##             ####       ##  ##     # ##  ##     ##  ##    ##\n");
        system("color 02");
        playSound1(C, quarterNote);
        playSound1(G, quarterNote);
        printf("\t\t\t    #######   #######  ##          ##              ##        ##  ##      ###  #######    ########\n");
        printf("\n\n");
        playSound1(Eb, quarterNote);
        playSound1(C, quarterNote);
        printf("\n\n\n");
        playSound1(Ab, quarterNote);
        playSound1(G, quarterNote); 
  			
	    printf("    *   ####    ##   ##  ##   ##    ####   #######   #####   ##   ##             ####   ######     ##     ##   ##  ####     #######  ###### *\n");
	    system("color 01");
	    playSound1(G, quarterNote);
        playSound1(F, quarterNote);
		printf("    *   ## ##   ##   ##  ###  ##   ##  ##   ##   #  ##   ##  ###  ##            ##  ##   ##  ##   ####    ##   ##   ##       ##   #   ##  ## *\n");
		playSound1(Eb, quarterNote);
	    playSound1(D, quarterNote);
		system("color 02");
        printf("    *   ##  ##  ##   ##  #### ##  ##        ## #    ##   ##  #### ##           ##        ##  ##  ##  ##   ##   ##   ##       ## #     ##  ## *\n");
        playSound1(C, 2 * quarterNote);
        system("color 03"); 
        printf("    *   ##  ##  ##   ##  ## ####  ##        ####    ##   ##  ## ####           ##        #####   ##  ##   ## # ##   ##       ####     ##### *\n");
        playSound1(G, quarterNote);
        playSound1(G, quarterNote);
        system("color 05");
        printf("    *   ##  ##  ##   ##  ##  ###  ##  ###   ## #    ##   ##  ##  ###           ##        ## ##   ######   #######   ##   #   ## #     ## ## *\n");
        playSound1(G, quarterNote);
        playSound1(Eb, 2 * quarterNote);
        system("color 06");
        printf("    *   ## ##   ##   ##  ##   ##   ##  ##   ##   #  ##   ##  ##   ##            ##  ##   ##  ##  ##  ##   ### ###   ##  ##   ##   #   ##  ## *\n");
        playSound1(G, quarterNote);
        playSound1(Eb, 2 * quarterNote);
        system("color 07");
        printf("    *   ####     #####   ##   ##    #####  #######   #####   ##   ##             ####   #### ##  ##  ##   ##   ##  #######  #######  #### ## *\n");
        playSound1(C, quarterNote);
        playSound1(G, quarterNote);
        system("color 03");
        playSound1(Eb, 2 * quarterNote); 
        playSound1(C, quarterNote);
		Sleep(700);
        system("cls || clear");
        
        printf("\n\n");
        printf("\t\t\t\t\t\t       > ###   ###  ####  ###  ##  ##  ## <\n");
        printf("\t\t\t\t\t\t       > #### ####  ##    #### ##  ##  ## <\n");
        printf("\t\t\t\t\t\t       > ## ### ##  ####  ## ####  ##  ## <\n");
        printf("\t\t\t\t\t\t       > ##     ##  ##    ##  ###  ##  ## <\n");
        printf("\t\t\t\t\t\t       > ##     ##  ####  ##   ##  ###### <\n");
        Beep(600,600);
        
        printf("\n\n");
        printf("\t\t\t\t\t\t         -----------------------------\n\n");
        Sleep(300);
		printf("\t\t\t\t\t\t\t         |===========|\n");
		printf("\t\t\t\t\t\t\t         |   JOGAR   |\n");
		printf("\t\t\t\t\t\t\t         |     1     |\n");
		printf("\t\t\t\t\t\t\t         |===========|\n\n");
	
        Sleep(300);
		printf("\t\t\t\t\t\t\t         |===========|\n");
		printf("\t\t\t\t\t\t\t         |  TUTORIAL |\n");
		printf("\t\t\t\t\t\t\t         |     2     |\n");
		printf("\t\t\t\t\t\t\t         |===========|\n\n");

        Sleep(300);
        printf("\t\t\t\t\t\t\t         |===========|\n");
		printf("\t\t\t\t\t\t\t         |   SAIR    |\n");
		printf("\t\t\t\t\t\t\t         |     3     |\n");
		printf("\t\t\t\t\t\t\t         |===========|\n\n");

        Sleep(300);
        printf("\t\t\t\t\t\t        ------------------------------\n");
        Sleep(300);
        printf("\n\t\t\t\t\t\t\t==> ");
        Beep(600,600);
        scanf("%d", &escolha_menu);

		system("cls || clear");

		switch(escolha_menu)
		{

		case (1):
			system("cls");
        	system("color 0D");
        	
			char abrir[] = "\n\n\t\t\t\t\t\t   . . . . . . ABRINDO JOGO . . . . . . ";
			
			int a;
		    for (a = 0; abrir[a] != '\0'; a++) {
		        printf("%c", abrir[a]);
		        fflush(stdout);
		        usleep(20000);
		    }
		     Sleep(500);
		    system("cls");
			Beep(700,700); 
			historinha();
			Jogo();
			
			
			break;
			
		case (2):
			
			system("cls");
        	system("color 07");
        	
			char tutorial[] = "\n\n\t\t\t\t\t\t   . . . . . . INICIANDO TUTORIAL . . . . . . ";
			
			int x;
		    for (x = 0; tutorial[x] != '\0'; x++) {
		        printf("%c", tutorial[x]);
		        fflush(stdout);
		        usleep(20000);
		    }
		    Sleep(500);
		    system("cls");
		  
		  	 // Thread para reproduzir a melodia
		    pthread_t melodyThread;
		    pthread_create(&melodyThread, NULL, playSonicMelody, NULL);
		
		    
		  char frase[] = "\n\t\t   ---------------------------------------------------####----------------------------------------------------------\n"
                   "\t\t   |   O jogo eh do estilo aventura/puzzle onde o objetivo eh o passar de tres fases. Em cada fase o jogador deve  |\n"
                   "\t\t   |   se passar de tres fases. Em cada fase o jogador deve se movimentar para pegar uma chave para abrir a porta  |\n"
                   "\t\t   |    fechada.                                                                                                   |\n"
                   "\t\t   ---------------------------------------------------####----------------------------------------------------------\n"
                   "\t\t   |   O jogador possui os seguintes comandos:                                                                     |\n"
                   "\t\t   |   O: Simbolo que representa o botao(abre passagens secretas)                                                  |\n"
                   "\t\t   |   W: O jogador movimenta uma unidade para cima.                                                               |\n"
                   "\t\t   |   A: O jogador movimenta uma unidade para a esquerda.                                                         |\n"
                   "\t\t   |   S: O jogador movimenta uma unidade para baixo.                                                              |\n"
                   "\t\t   |   D: O jogador movimenta uma unidade para direita.                                                            |\n"
                   "\t\t   |   I: O jogador interage com o objeto que ele estiver em cima.                                                 |\n"
                   "\t\t   ---------------------------------------------------####----------------------------------------------------------\n"
                   "\t\t   |   @: Simbolo que representa o jogador.                                                                        |\n"
                   "\t\t   |   #: Simbolo que representa uma parede, o jogador nao pode passar pela parede.                                |\n"
                   "\t\t   |   &: Simbolo que representa a chave para abrir a porta para finalizar a fase,                                 |\n"
                   "\t\t   |   a porta abre no momento em que o jogador interage com a chave.                                              |\n"
                   "\t\t   |   D: Simbolo que representa uma porta fechada.                                                                |\n"
                   "\t\t   |   =: Simbolo que representa uma porta que foi aberta quando o jogador interagiu com a chave.                  |\n"
                   "\t\t   |   *: Simbolo que representa um espinho(tira uma vida).                                                        |\n"
                   "\t\t   |   >: simbolo que representa um teletransporte.O teletransporte sempre deve                                    |\n"
                   "\t\t   |   vir em par, quando o jogador toca em um ele e transportado para outro e vice-versa.                         |\n"
                   "\t\t   |   O guardiao do portal, jogue uma rodada e derrote o oponente para passar pelo portal vencer o jogo.          |\n"
                   "\t\t   ---------------------------------------------------####----------------------------------------------------------\n"
                   "\t\t   |     O JOGADOR POSSUI UM TOTAL DE 3 VIDAS, SE PERDER TODAS AS VIDAS O JOGO VOLTA PARA O MENU INICIAL.          |\n"
                   "\t\t   --------------------------------------------------####----------------------------------------------------------\n";
		
		  // Exibição do texto da 
		    int t;
		    for (t = 0; frase[t] != '\0'; t++) {
		        printf("%c", frase[t]);
		        fflush(stdout);
		        usleep(1000);
		    }
		    
		    // Aguardar a finalização da thread da melodia
		    pthread_join(melodyThread, NULL);
		
		    printf("\n\n\t\t\t\tDigite 1 e de enter para continuar...");
		    int lixo;
		    printf("\n\t\t\t\t==> ");
		    scanf("%d", &lixo);
			break;
			
		case (3):	

			system("cls");
        	system("color 04");
			char encerrando[] = "\n\n\t\t\t\t\t\t  . . . . . . ENCERRANDO JOGO . . . . . . ";
			
			int e;
		    for (e = 0; encerrando[e] != '\0'; e++) {
		        printf("%c", encerrando[e]);
		        fflush(stdout);
		        usleep(20000);
		    }
		     Sleep(500);
		    system("cls");
          	
			printf("\t\t######## ######### ########    ########     #######   #######  ########  ##      ##  ##  ###          ###  ########\n");
			system("color 0C");
			Sleep(200);
			printf("\t\t##    ##    ##     ##          ##    ##     ##     ## ##    ## ##    ##   ##    ##   ##  ## #        # ##  ##    ##\n");
			system("color 04");
			Sleep(200);
			printf("\t\t##    ##    ##     ##          ##    ##     ##     ## ##    ## ##    ##    ##  ##    ##  ##  #      #  ##  ##    ##\n");
			system("color 0C");
			Sleep(200);
			printf("\t\t########    ##     #####       ########     #######   ######   ##    ##    #####     ##  ##   #    #   ##  ########\n");
			printf("\t\t ##    ##    ##     ##         ##    ##     ##        ## ##    ##    ##    ## ##     ##  ##    #  #    ##  ##    ##\n");
			system("color 04");
			Sleep(200);
			printf("\t\t##    ##    ##     ##          ##    ##     ##        ##  ##   ##    ##   ##   ##    ##  ##     ##     ##  ##    ##\n");
			system("color 0C");
			Sleep(200);
			printf("\t\t##    ##    ##     ########    ##    ##     ##        ##   ##  ########  ##     ##   ##  ##            ##  ##    ##\n");
			system("color 04");
			Sleep(900);
			system("cls");
		
		    
			//CREDITOS FINAIS 
			char frase2[]= "\t\t\t\t\t     |=================== CREDITOS ====================|\n"
			 "\t\t\t\t\t     |                                                 |\n"
		     "\t\t\t\t\t     |             ------- ALUNOS -------              |\n"
		     "\t\t\t\t\t     |                                                 |\n"
		     "\t\t\t\t\t     | ELISSANDRA NASCIMENTO - 23300025                |\n"
		     "\t\t\t\t\t     | RENAN ABREU DE ALMEIDA - 23300041               |\n"
		     "\t\t\t\t\t     | LUIZ EDUARDO NETO DOS SANTOS - 23300032         |\n"
		     "\t\t\t\t\t     |                                                 |\n"
		     "\t\t\t\t\t     |           ------- PROFESSOR -------             |\n"
		     "\t\t\t\t\t     |                                                 |\n"
		     "\t\t\t\t\t     | PEDRO HENRIQUE SALES GIROTTO                    |\n"
		     "\t\t\t\t\t     |                                                 |\n"
		     "\t\t\t\t\t     |          ------- INSTITUICAO -------            |\n"
		     "\t\t\t\t\t     |                                                 |\n"
		     "\t\t\t\t\t     | CENTRO UNIVERSITARIO DO ESTADO DO PARA - CESUPA |\n"
		     "\t\t\t\t\t     |                                                 |\n"
		     "\t\t\t\t\t     |=================================================|\n";
		    
			
			// Exibição do texto dos creditos
		    int c;
		    for (c = 0; frase2[c] != '\0'; c++) {
		        printf("%c", frase2[c]);
		        fflush(stdout);
		        usleep(1000);
		    }
		    
		    printf("\n\t\t\t\t\t  DIGITE 0 PARA SAIR\n");
		    printf("\t\t\t\t\t  ==> ");
			scanf("%d", &lixo);
			Beep(100,1000);
			
			break;
				
		}
			
		}


return 0;
}
endconio();









