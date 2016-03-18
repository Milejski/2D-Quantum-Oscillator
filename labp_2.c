#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void){
	clock_t t[2];	//used to calculate run time
	t[0]=clock();
	float wx;	//potencial field parameters
	float wy;
	double Lx; //size of the calculation plane
	double Ly;	
	int nx;
	int ny;
	int N;		//number of states to calculate after base state
	double dx;
	double dy;
	double C;
	float dT;	//imaginary time method parameter
	FILE *fprob;		//propability density function file
	FILE *fpotencial;	//potencial function file
	FILE *fenergy;		//energy values file
	FILE *finput;		//user input file
	int i,j,g,s,k=0;
	if ((fprob=fopen("labp_f.txt", "w"))==NULL){
		printf ("Error - file labp_f.txt could not be opened!\n");
		exit(1);
	}
	if ((fpotencial=fopen("labp_V.txt", "w"))==NULL){
		printf ("Error - file labp_V.txt could not be opened!\n");
		exit(1);
	}
	if ((fenergy=fopen("labp_E.txt", "w"))==NULL){
		printf ("Error - file labp_E.txt could not be opened!\n");
		exit(1);
	}
	if ((finput=fopen("labp_data.txt", "r"))==NULL){
		printf ("Error - file labp_data.txt could not be opened!\n");
		exit(1);
	}
	if(fscanf(finput,"%f\n%f\n%f\%d\n%d\n%d",&wx,&wy,&dT,&nx,&ny,&N)==6){ //reading user input from file
		wx*=0.0364;
		wy*=0.0364;
	}else{
		printf("Error - could not read data from file!\n");
		exit(1);
	}
	Lx=20*pow(1/wx,0.5);
	Ly=20*pow(1/wy,0.5);
	dx=Lx/nx;
	dy=Ly/ny;
	double V[nx+1][ny+1];	//values of the potencial field
	double f[nx+1][ny+1][2];	//f[i][j][0] contains values from last iteration, f[i][j][1] contains values from current iteration
	double F[nx+1][ny+1][N+1];	//F[i][j][n] contains final iteration for n state
	double e[2];		//e[0] energy from last iteration, e[1] energy from current iteration
	double E[N+1];		//E[n] contains final energy for n state
	
	for(i=0;i<=nx;i++){	//calculating potencial field values
		for(j=0;j<=ny;j++){
			V[i][j]=(pow(wx*(i*dx-Lx/2.),2.)+pow(wy*(j*dy-Ly/2.),2.))/2.;
			fprintf(fpotencial,"%f\t%f\t%E\n",i*dx/18.897,j*dy/18.897,V[i][j]/0.0364);
		}
	}
	fclose(fpotencial);
	
	srand(time(NULL));
	for(g=0;g<=N;g++){	//g represent current state, for which calculations are made, this loop contains the most of calculations
		for(i=0;i<=nx;i++){	//filing function with random values, making sure border values are zeroed
			for(j=0;j<=ny;j++){
				if((i==0)||(j==0)||(i==nx)||(j==ny)){f[i][j][0]=0.;}
				else{f[i][j][0]=(rand()%10000)/10000.;}
			}
		}
		e[0]=0.;
		
		for(k=0;k<g;k++){ //orthogonalisation of function f[i][j][0]
			C=0.;
			for(i=0;i<=nx;i++){
				for(j=0;j<=ny;j++){
					F[i][j][g]=f[i][j][0];
					C+=F[i][j][k]*F[i][j][g];
				}
			}
			for(i=0;i<=nx;i++){
				for(j=0;j<=ny;j++){
					f[i][j][0]-=C*F[i][j][k];
				}
			}
		}
		
		C=0.;		//normalisation
		for(i=0;i<=nx;i++){
			for(j=0;j<=ny;j++){
				C+=pow(f[i][j][0],2);
			}
		}
		C=pow(C,0.5);
		for(i=0;i<=nx;i++){
			for(j=0;j<=ny;j++){
				f[i][j][0]/=C;
			}
		}
		
		for(s=1;;s++){	//starting function evolution
			for(i=0;i<=nx;i++){
				for(j=0;j<=ny;j++){
					if((i==0)||(j==0)||(i==nx)||(j==ny)){f[i][j][1]=0.;}
					else{f[i][j][1]=
						f[i][j][0]-dT*(
						(f[i-1][j][0]-2.*f[i][j][0]+f[i+1][j][0])/pow(dx,2.)/-2.+
						(f[i][j-1][0]-2.*f[i][j][0]+f[i][j+1][0])/pow(dy,2.)/-2.+
						V[i][j]*f[i][j][0]);}
				}
			}

			for(k=0;k<g;k++){	//orthogonalisation
				C=0.;
				for(i=0;i<=nx;i++){
					for(j=0;j<=ny;j++){
						F[i][j][g]=f[i][j][1];
						C+=F[i][j][g]*F[i][j][k];
					}
				}
				for(i=0;i<=nx;i++){
					for(j=0;j<=ny;j++){
						f[i][j][1]-=C*F[i][j][k];
					}
				}
			}
			
			C=0.;		//normalisation
			for(i=0;i<=nx;i++){
				for(j=0;j<=ny;j++){
					C+=pow(f[i][j][1],2);
				}
			}
			C=pow(C,0.5);
			for(i=0;i<=nx;i++){
				for(j=0;j<=ny;j++){
					f[i][j][1]/=C;
				}
			}
			
			e[1]=0.;
			for(i=1;i<=nx-1;i++){ //calculating energy value for current function iteration
				for(j=1;j<=nx-1;j++){
					e[1]+=f[i][j][1]*(
					(f[i-1][j][1]-2.*f[i][j][1]+f[i+1][j][1])/pow(dx,2.)/-2.+
					(f[i][j-1][1]-2.*f[i][j][1]+f[i][j+1][1])/pow(dy,2.)/-2.+
					V[i][j]*f[i][j][1]);
				}
			}
			
			if(fabs(e[1]-e[0])<=fabs(e[1])*0.000001){break;} //cheking, if energy value stoped changing
			if(s%1000==0){
				printf("+");
				//printf("Value: %e\tEnergy diffrence: %e\tEnergy value: %e\n",e[1]/0.0364,fabs(e[1]-e[0])/0.0364,fabs(e[1])*0.00001/0.0364);
			}
			e[0]=e[1];
			for(i=0;i<=nx;i++){
				for(j=0;j<=ny;j++){
					f[i][j][0]=f[i][j][1];
				}
			}
		}
		
		E[g]=e[1];	//writing final values to designated variables
		for(i=0;i<=nx;i++){
			for(j=0;j<=ny;j++){
				F[i][j][g]=f[i][j][1];
			}
		}
		
		fprintf(fenergy,"%f\n",E[g]/0.0364); //writing calculated values to designated files
		for(i=0;i<=nx;i++){
			for(j=0;j<=ny;j++){
				fprintf(fprob,"%f\t%f\t%E\n",i*dx/18.897,j*dy/18.897,pow(F[i][j][g],2.));
			}
		}
		
		printf("\nIteration count %d :%d\nCalculated energy: %f eV\nChecking orthonormalisation:\n",g,s,E[g]/0.0364); //checking orthonormalisation of calculated functions (just to be sure)
		for(k=0;k<=g;k++){
			C=0.;
			for(i=0;i<=nx;i++){
				for(j=0;j<=ny;j++){
					C+=F[i][j][g]*F[i][j][k];
				}
			}
			printf("%e\t",C);
		}
		t[1]=clock();
		printf("\nCalculation time :%f s\n",(double)(t[1]-t[0])/CLOCKS_PER_SEC);
	}
	
	fclose(fprob);
	fclose(fenergy);
	return 0;
}