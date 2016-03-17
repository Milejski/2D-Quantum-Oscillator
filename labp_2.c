#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void)
{
	////////// Deklaracja zmiennych//////////
	clock_t t[2];
	t[0]=clock();
	float wx;		
	float wy;	
	double Lx;
	double Ly;
	int nx;
	int ny;
	int N;		//ile stanów dodatkowych program ma liczyć, w sumie liczy N+1 stanów,
	double dx;
	double dy;
	double C;
	float dT;
	FILE *fp1;		//zapis funkcji gęstości prawdopodobieństwa
	FILE *fp2;		//zapis funkcji potencjału
	FILE *fp3;		//zapis energii
	FILE *fp4;		//wczytywanie wartości wx,wy,nx,ny,N,dT
	int i,j,g,s,k=0;
	if ((fp1=fopen("labp_f.txt", "w"))==NULL)
	{
		printf ("Nie moge otworzyc pliku labp_f.txt do zapisu!\n");
		exit(1);
	}
	if ((fp2=fopen("labp_V.txt", "w"))==NULL)
	{
		printf ("Nie moge otworzyc pliku labp_V.txt do zapisu!\n");
		exit(1);
	}
	if ((fp3=fopen("labp_E.txt", "w"))==NULL)
	{
		printf ("Nie moge otworzyc pliku labp_E.txt do zapisu!\n");
		exit(1);
	}
	if ((fp4=fopen("labp_data.txt", "r"))==NULL)
	{
		printf ("Nie moge otworzyc pliku labp_data.txt do zapisu!\n");
		exit(1);
	}
	
	////////// Czytanie zmiennych z pliku //////////
	if(fscanf(fp4,"%f\n%f\n%f\%d\n%d\n%d",&wx,&wy,&dT,&nx,&ny,&N)==6)
	{
		wx*=0.0364;
		wy*=0.0364;
	}else{
		printf("Błąd czytania z pliku\n");
		exit(1);
	}
	Lx=20*pow(1/wx,0.5);
	Ly=20*pow(1/wy,0.5);
	dx=Lx/nx;
	dy=Ly/ny;
	double V[nx+1][ny+1];	//przechowuje potencjał
	double f[nx+1][ny+1][2];//f[i][j][0] funkcja z poprzedniej iteracji, f[i][j][1] funkcja z najnowszej iteracji
	double F[nx+1][ny+1][N+1];
	double e[2];		//e[0] energia z poprzedniej iteracji, e[1] energia z najnowszej iteracji
	double E[N+1];		//E[i] - energia stanu i;
	////////// Inicjalizacja potencjału //////////
	for(i=0;i<=nx;i++)
	{
		for(j=0;j<=ny;j++)
		{
			V[i][j]=(pow(wx*(i*dx-Lx/2.),2.)+pow(wy*(j*dy-Ly/2.),2.))/2.;
			fprintf(fp2,"%f\t%f\t%E\n",i*dx/18.897,j*dy/18.897,V[i][j]/0.0364);		//Zapisywanie potencjału do pliku w eV.
		}
	}
	fclose(fp2);
	
	
	for(g=0;g<=N;g++)
	{
		////////// Inicjalizacja funkcji przy pomocy generatora liczb losowych i liczenie całki do normalizacji //////////
		C=0.;
		srand(time(NULL));
		for(i=0;i<=nx;i++)
		{
			for(j=0;j<=ny;j++)
			{
				if((i==0)||(j==0)||(i==nx)||(j==ny)){f[i][j][0]=0.;}
				else{f[i][j][0]=(rand()%10000)/10000.;}
				C+=pow(f[i][j][0],2.);
			}
		}
		C=pow(C,0.5);
		
		////////// Normalizacja funkcji //////////
		for(i=0;i<=nx;i++)
		{
			for(j=0;j<=ny;j++)
			{
				f[i][j][0]/=C;
				F[i][j][g]=f[i][j][0];
			}
		}
		e[0]=0.;
		
		////////// Ortogonalizacja funkcji //////////
		for(k=0;k<g;k++)
		{
		C=0.;
			for(i=0;i<=nx;i++)
			{
				for(j=0;j<=ny;j++)
				{
					C+=F[i][j][k]*F[i][j][g];
				}
			}
			for(i=0;i<=nx;i++)
			{
				for(j=0;j<=ny;j++)
				{
					f[i][j][0]-=C*F[i][j][k];
				}
			}
		}
		
		////////// Ponowna normalizacja funkcji //////////
		if(f>0)
		{
			C=0;
			for(i=0;i<=nx;i++)
			{
				for(j=0;j<=ny;j++)
				{
					C+=pow(f[i][j][0],2.);
				}
			}
			C=pow(C,0.5);
			for(i=0;i<=nx;i++)
			{
				for(j=0;j<=ny;j++)
				{
					f[i][j][0]/=C;
				}
			}
		}
		
		////////// Pętla ewolucji funkcji //////////
		for(s=1;;s++)
		{
			C=0.;
			////////// Wartość funkcji dla kroku s //////////
			for(i=0;i<=nx;i++)
			{
				for(j=0;j<=ny;j++)
				{
					if((i==0)||(j==0)||(i==nx)||(j==ny)){f[i][j][1]=0.;}
					else{f[i][j][1]=
						f[i][j][0]-dT*(
						(f[i-1][j][0]-2.*f[i][j][0]+f[i+1][j][0])/pow(dx,2.)/-2.+
						(f[i][j-1][0]-2.*f[i][j][0]+f[i][j+1][0])/pow(dy,2.)/-2.+
						V[i][j]*f[i][j][0]);}
					C+=pow(f[i][j][1],2.);
				}
			}
			C=pow(C,0.5);
			
			////////// Normalizacja funkcji //////////
			for(i=0;i<=nx;i++)
			{
				for(j=0;j<=ny;j++)
				{
					f[i][j][1]/=C;
					F[i][j][g]=f[i][j][1];
				}
			}
									
			////////// Ortogonalizacja funkcji //////////
			for(k=0;k<g;k++)
			{
				C=0.;
				for(i=0;i<=nx;i++)
				{
					for(j=0;j<=ny;j++)
					{
						C+=F[i][j][g]*F[i][j][k];
					}
				}
				for(i=0;i<=nx;i++)
				{
					for(j=0;j<=ny;j++)
					{
						f[i][j][1]-=C*F[i][j][k];
					}
				}
			}
				
			////////// Ponowna normalizacja funkcji //////////
			if(g>0)
			{
				C=0.;
				for(i=0;i<=nx;i++)
				{
					for(j=0;j<=ny;j++)
					{
						C+=pow(f[i][j][1],2.);
					}
				}
				C=pow(C,0.5);
				for(i=0;i<=nx;i++)
				{
					for(j=0;j<=ny;j++)
					{
						f[i][j][1]/=C;
					}
				}
			}
				
			////////// Obliczanie wartości E //////////
			e[1]=0.;
			for(i=1;i<=nx-1;i++)
			{
				for(j=1;j<=nx-1;j++)
				{
					e[1]+=f[i][j][1]*(
					(f[i-1][j][1]-2.*f[i][j][1]+f[i+1][j][1])/pow(dx,2.)/-2.+
					(f[i][j-1][1]-2.*f[i][j][1]+f[i][j+1][1])/pow(dy,2.)/-2.+
					V[i][j]*f[i][j][1]);
				}
			}
			
			////////// Sprawdzanie warunku i przepisanie wartości //////////
			if(fabs(e[1]-e[0])<=fabs(e[1])*0.000000001) {break;}
			if(s%1000==0) {printf("+");}
			e[0]=e[1];
			for(i=0;i<=nx;i++)
			{
				for(j=0;j<=ny;j++)
				{
					f[i][j][0]=f[i][j][1];
				}
			}
		}
		
		////////// Przepisanie uzyskanych wartości ze zmiennych iterowanych do zmiennych końcowych //////////
		E[g]=e[1];
		for(i=0;i<=nx;i++)
		{
			for(j=0;j<=ny;j++)
			{
				F[i][j][g]=f[i][j][1];
			}
		}
		
		////////// Zapis do pliku //////////
		fprintf(fp3,"%f\n",E[g]/0.0364);
		for(i=0;i<=nx;i++)
		{
			for(j=0;j<=ny;j++)
			{
				fprintf(fp1,"%f\t%f\t%E\n",i*dx/18.897,j*dy/18.897,pow(F[i][j][g],2.));
			}
		}
		
		////////// Sprawdzanie ortogonalności otrzymanych funkcji //////////
		printf("\nIlosc iteracji dla stanu %d :%d\nOtrzymana energia: %f eV\n",g,s,E[g]/0.0364);
		for(k=0;k<=g;k++)
		{
			C=0.;
			for(i=0;i<=nx;i++)
			{
				for(j=0;j<=ny;j++)
				{
					C+=F[i][j][g]*F[i][j][k];
				}
			}
			printf("%e\t",C);
		}
		printf("\n");
		t[1]=clock();
		printf("Czas obliczen :%f s\n",(double)(t[1]-t[0])/CLOCKS_PER_SEC);
	}
	
	fclose(fp1);
	fclose(fp3);
	return 0;
}
