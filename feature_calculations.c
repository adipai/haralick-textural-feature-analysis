#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define r 10
#define c 10

/*1*/void angsecmom(int p[r][c])
{
 int i, j;
 double asm1 = 0 ;

 for(i = 0 ; i < r ; i++)
 {
  for(j = 0 ; j < c ; j++)
  {
   asm1 = asm1 + (p[i][j]*p[i][j]) ;
  }
 }

 printf("Angular second Moment : %f\n",asm1);
 // Printing the angular second moment

}


/*2*/void con(int p[r][c])
{
 double f2=0, p1=0,n;
 int i,j;

 for (i=1; i<=r; i++)
 {
  for (j=1;j<=c;j++)
  {
   p1=p1+p[i][j]; //Calculating the summation of P[i][j]
  }
 }

 for (i=1;i<r;i++)
 {
  for (j=1;j<c;j++)
  {
   n=abs(i-j);
   f2=f2+((n*n)*p1);
  }
 }

 printf("Contrast : %f\n",f2); //Printing the contrast

}


/*3*/void correlation(int p[r][c])
{
 int i,j;

 double ux,uy;
 //ux and uy are means of px and py respectively
 double sdev_x,sdev_y;
 //sdev_x and sdev_y are standard deviations of px and py respectively

 double corr=0;//correlation
 double sum =0;

 ux=0,uy=0;
 sdev_x=0,sdev_y=0;

 //to find ux
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   ux+=(i*p[i][j]);
  }
 }

 //to find uy
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   uy+=(j*p[i][j]);
  }
 }

 //to find sdev_x
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   sdev_x+=(((i-ux)*(i-ux))*p[i][j]);
  }
 }
 sdev_x=sqrt(sdev_x);

 //to find sdev_y
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   sdev_y+=(((i-uy)*(i-uy))*p[i][j]);
  }
 }
 sdev_y=sqrt(sdev_y);

 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   sum +=((i*j)*p[i][j]);
  }
 }

 corr=(sum-(ux*uy))/(sdev_x*sdev_y);

 printf("correlation=%f\n",corr);

}


/*4*/void variance(int p[r][c])
{
 int i,j,sum=0;
 double var=0.000000;
 double u;

 for(i=0;i<r;i++)// sum of all grey levels
 {
  for(j=0;j<c;j++)
  {
   sum+=p[i][j];
  }
 }

 u = sum/(r*c);//mean of grey levels

 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   var+=(((i-u)*(i-u))*p[i][j]);
  }
 }

 printf("Variance : %f\n",var);
}


/*5*/void indifmom(int p[r][c])
{
 int i,j;
 double res=0;

 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   res= res + ((1/(1+((i-j)*(i-j)))*p[i][j]));
  }
 }

 printf("Inverse Difference Moment: %f\n ",res);
}


/*6*/void sum_avg(int P[r][c])
{
 int i,j;
 double f6=0, px[10][10],py[10][10],pxy[10][10], pm[10][10];

 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   pm[i][j]=0;
  }
 }

 for (i=0; i<r; i++)
 {
  for (j=0;j<c;j++)
  {
   px[i][j]=i*(P[i][j]); //Calculating Px
   py[i][j]=j*(P[i][j]); //Calculating Py
  }
 }

 for (i=0; i<r; i++)
 {
  for (j=0;j<c;j++)
  {
   pxy[i][j]=px[i][j]+py[i][j];
  }
 }

 for (i=0; i<r; i++)
 {
  for (j=0;j<c;j++)
  {
   pm[i][j]=pm[i][j]+pxy[i][j]; //Calculating the pm
   f6=f6+(i*pm[i][j]); //Calculating the sum average
  }
 }

 printf("Sum Average : %f\n",f6);
}


/*7&8*/ void sum_entropy_variance(int p[r][c])
{
 int i,j;
 double f7=0,f8=0; int px[r][c],py[r][c],pxy[r][c], pm[r][c];

 for (i=1; i<=r; i++)
 {
  for (j=1;j<=c;j++)
  {
   px[i][j]=i*(p[i][j]); //Calculating Px
   py[i][j]=j*(p[i][j]); //Calculating Py
  }
 }

 for (i=1; i<r; i++)
 {
  for (j=1;j<c;j++)
  {
   pxy[i][j]=px[i][j]+py[i][j];
  }
 }

 for (i=2; i<=r; i++)
 {
  for (j=1;j<=c;j++)
  {
   pm[i][j]=pm[i][j]+pxy[i][j];
   //Calculating the pm
   f8=( f8 + ( pm[i][j] * ( log ( pm[i][j] ) ) ) ) * -1;
   //Calculating the sum entropy
   f7=( f7 + ( (  ( 1-f8 )*(1-f8 )*pm[i][j] ) ) );
   // Calculating the sum variance
  }
 }

 printf ("Sum entropy : %f\n",f8); // Printing the sum entropy
 printf ("Sum variance : %f\n",f7); // Printing the sum variance

}

/*9*/double entropy(int p[r][c])
{
 int i,j;
 double ent=0;

 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   ent+=(p[i][j]*log(p[i][j]));
  }
 }
   return -ent;
  //printf("Entropy : %f\n",(-ent));

}


/*10*/void dif_var(int p[r][c])
{
 int u,i,j;
 double f10=0.000000,diff=0.000000; int px[r][c],py[r][c],pxy[r][c], pm[r][c];

 for (i=0; i<r; i++)
 {
  for (j=0;j<c;j++)
  {
   px[i][j]=i*(p[i][j]); //Calculating Px
   py[i][j]=j*(p[i][j]); //Calculating Py
  }
 }

 for (i=0; i<r; i++)
 {
  for (j=0;j<c;j++)
  {
   pxy[i][j]=px[i][j]-py[i][j];
   diff=diff-pxy[i][j];
  }
 }

 u=diff/(r+c);

 for (i=0; i<r; i++)
 {
  for (j=0;j<c;j++)
  {
   f10=( f10 + ( ((i-u)*(i-u)) * pxy[i][j] ) ) ; //Calculating the difference variance
  }
 }

 printf ("Difference variance : %f\n",f10); // Printing the difference variance

}


/*11*/void dif_entropy(int p[r][c])
{
 int i,j;
 double f11=0; int px[r][c],py[r][c],pxy[r][c], pm[r][c];

 for (i=1; i<=r; i++)
 {
  for (j=1;j<=c;j++)
  {
   px[i][j]=i*(p[i][j]); //Calculating Px
   py[i][j]=j*(p[i][j]); //Calculating Py
  }
 }

 for (i=1; i<r; i++)
 {
  for (j=1;j<c;j++)
  {
   pxy[i][j]=px[i][j]-py[i][j];
  }
 }

 for (i=0; i<=r; i++)
 {
  for (j=0;j<=c;j++)
  {
   pm[i][j]=pm[i][j]-pxy[i][j]; //Calculating the pm
   f11=( f11 + ( pm[i][j] * ( log ( pm[i][j] ) ) ) ); //Calculating the difference entropy
  }
 }

 printf ("Difference entropy : %f\n",f11); // Printing the difference entropy

}


/*12*/void imc1(int p[r][c])
{
 int i,j;
 double max;
 double HXY=0, px, py, HX,HY, HXY1, HXY2;

 for (i=1; i<=r; i++)
 {
  for (j=1;j<=c;j++)
  {
   px=px+(i*(p[i][j])); //Calculating Px
   py=py+(j*(p[i][j])); //Calculating Py
  }
 }

 for (i=1; i<=r; i++)
 {
  for (j=1;j<=c;j++)
  {
   HX=( HX + ( px * ( log ( px ) ) ) ) ; //Calculating HX
   HX=-HX;
   HY=( HY + ( py * ( log ( py ) ) ) ) ; //Calculating HY
   HY=-HY;
  }
 }

 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   HXY=HXY+((p[i][j]*log(p[i][j])));
  }
 }

 for (i=1; i<=r; i++)
 {
  for (j=1;j<=c;j++)
  {
   HXY1 =HXY1 + ( p[i][j] * ( log ( px * py) ) ) ; //Calculating HXY1
   HXY1 = - HXY1;
   HXY2 = HXY2 + ( (px*py) * (log ( px *py ) ) ) ; //Calculating HXY2
   HXY2 = - HXY2;
  }
 }

 //finding th maximum of hx and hy
 if(HX>HY)
  max=HX;
 else
  max=HY;

 printf("IMC1 = %f\n",(HXY-HXY1)/max);

}

/*13*/void imc2(int p[r][c])
{
 int i,j;
 double h;
 double HXY=0, px, py, HX,HY, HXY1, HXY2;

 for (i=1; i<=r; i++)
 {
  for (j=1;j<=c;j++)
  {
   px=px+(i*(p[i][j])); //Calculating Px
   py=py+(j*(p[i][j])); //Calculating Py
  }
 }

 for (i=1; i<=r; i++)
 {
  for (j=1;j<=c;j++)
  {
   HX=( HX + ( px * ( log ( px ) ) ) ) ; //Calculating HX
   HX=-HX;
   HY=( HY + ( py * ( log ( py ) ) ) ) ; //Calculating HY
   HY=-HY;
  }
 }

 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   HXY=HXY+((p[i][j]*log(p[i][j])));
  }
 }

 for (i=1; i<=r; i++)
 {
  for (j=1;j<=c;j++)
  {
   HXY1 =HXY1 + ( p[i][j] * ( log ( px * py) ) ) ; //Calculating HXY1
   HXY1 = - HXY1;
   HXY2 = HXY2 + ( (px*py) * (log ( px *py ) ) ) ; //Calculating HXY2
   HXY2 = - HXY2;
  }
 }

 h=sqrt(1-exp(-2*(HXY2-HXY)));
 printf("IMC2 = %f\n",h);

}


void main()
{
 int p[10][10];
/* int p[r][c]={(42,40,39,39,39,38,38,38,33,34),
(40,40,40,40,39,38,37,36,40,41),
(39,41,41,39,38,38,37,36,41,41),
(39,41,41,38,36,37,39,38,40,40),
(38,41,41,38,37,38,40,41,39,39),
(38,39,40,40,38,38,40,41,40,40),
(40,39,39,39,39,37,39,42,42,41),
(42,39,37,38,37,36,39,43,39,38),
(39,37,37,38,37,38,40,40,38,40),
(37,36,37,38,38,39,40,39,39,41),
};*/
 int i,j;
 double e;
 char help[100],*token;

 FILE* myfile;
 clrscr();
 myfile=fopen("sample1.txt","r");

 i=0;

 while(!feof(myfile))
 {
  fscanf(myfile,"%s",help);
  token=strtok(help,",");

  j=0;

  while(token!=NULL)
  {
   p[i][j]=atoi(token);
   token=strtok(NULL,",");
   j++;
  }
  i++;
 }

   angsecmom(p);
   con(p);
   correlation(p);
   variance(p);
   indifmom(p);
   sum_avg(p);
 //sum_entropy_variance(p);
   e=entropy(p);
   printf("Entropy=%f\n",e);
   dif_var(p);
 //dif_entropy(p);
 //imc1(p);
 //imc2(p);

//to print matrix
/* for(i=0;i<10;i++)
 {
  for(j=0;j<10;j++)
  {
   printf("%d\t",p[i][j]);
  }
  printf("\n");
 }
*/

}
