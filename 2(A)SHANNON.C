#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
char str[20][10];
void group1();
void main()
{
float temp,info,eff,hx=0.0,l=0.0;
int j,low,high,x;
float a[20],sum=0.0;
int i,n;
clrscr();
printf("\n enter the no.of symbols:");
scanf("%d",&n);
while(sum!=1)//accepting proablities
{
printf("\nenter the probabilities:");
for(i=0;i<n;i++)
{
 {
 printf("\na%d:",i+1);
 scanf("%f",&a[i]);
 }
}
//cheking of prob.
sum=0.0;
for(i=0;i<n;i++)
sum=sum+a[i];
 if(sum!=1)
 printf("\n probabilities are not correct................enter again");
}//while
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]<a[j])
 {
 temp=a[i];
 a[i]=a[j];
 a[j]=temp;
 }
 }
}
printf("\n the probabilities are:\n");
for(i=0;i<n-1;i++)
{
printf("\t%.2f",a[i]);
}
printf("%.2f",a[i]);
low=0;
high=n-1;
group1(a,low,high);
printf("\nno.\tprobabilities\tcode\tcodelength\tinformation\n");
j=0;
for(i=0;i<n;i++)
{
info=log(1/a[i]);
info=info/log(2);
x=strlen(str[i]);
l=l+(x*a[i]);
printf(" %d\t%f\t%s\t%d\t\t%f\n",i+1,a[i],str[i],x,info);
}
for(i=0;i<n;i++)
{
hx=hx+(a[i]*(log(1/a[i])));
}
hx=hx/log(2);
eff=hx/l;
printf("\naverage codelength is:%f\nthe entropy is:%f\nthe efficiencyis:%f\nthe redundancy is:%f",l,hx,eff*100,(1-eff)*100);
getch();
}//main

void group1(float a[],int low,int high)
{
float sum2,half,no,newdiff,diff;
int pos,i,j;
if(low<high)
 {
 sum2=0;
 for(i=low;i<=high;i++)
 sum2=sum2+a[i];
 half=sum2/2;
 sum2=0.0;
 sum2=sum2+a[low];
 diff=half-sum2;
 if(diff<0)
 diff=-1*diff;
 for(i=low+1;i<=high;i++)
 {
 sum2=sum2+a[i];
 newdiff=half-sum2;
 if(newdiff<0)
 newdiff=-1*newdiff;
 if(newdiff<diff)
 diff=newdiff;
 else
 break;
}
pos=i-1;
for(j=low;j<=pos;j++)
{
strcat(str[j],"0");
}
for(j=pos+1;j<=high;j++)
{
strcat(str[j],"1");
}
group1(a,low,pos);
group1(a,pos+1,high);
}
}//group

/*OUTPUT:-
 enter the no.of symbols:7
enter the probabilities:
a1:0.4
a2:0.2
a3:0.08
a4:0.08
a5:0.08
a6:0.08
a7:0.04
 probabilities are not correct................enter again
enter the probabilities:
a1:0.4
a2:0.2
a3:0.12
a4:0.08
a5:0.08
a6:0.08
a7:0.04
 the probabilities are: 0.40    0.20    0.12    0.08    0.08    0.080.04
 no.    probabilities   code    codelength      information
1       0.400000        0       1       1.321928
2       0.200000        100     3       2.321928
3       0.120000        101     3       3.058894
4       0.080000        1100    4       3.643856
5       0.080000        1101    4       3.643856
6       0.080000        1110    4       3.643856
7       0.040000        1111    4       4.643856
average codelength is:2.480000
the entropy is:2.420504
the efficiencyis:97.600961
the redundancy is:2.399039 */
