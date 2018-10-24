//Syed Siraj Ul Haque ITU/s98/01144-A

#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>

class box{
	  public:
	  char state;
	  int group[20];
	  int count;
	  int dc;
	  box(){dc=0;state='0';group[0]=0;count=0;}
	  void input(char a) {state=a;}
	  void ingroup(int a){group[++count]=a;}
	  void showg(void)
		    {
		    for(int a=0;a<count+1;a++)cout<<group[a]<<" ";
		    cout<<"("<<count<<")";
		    }
	  int comp(box t)
		  {for(int a=0;a<count+1;a++)
		     {
		     for(int b=0;b<t.count+1;b++)
			{
			if(group[a]==t.group[b] && group[a]!=0){return group[a];}
			}
		     }
		  return 0;
		  }
	  } table[4][4];
int g=0,x=0;
char ans[100];
void bar(void);
int scan(void);
int scan16(void);
int scan8(void);
int scan4l(void);
int scan4(void);
int scan2(void);
int scan1(void);
void group8(int,int,int);
int group4l(int,int,int);
int group4(int,int,int);
int group2(int,int,int,int);
int len(char []);
void side(void);
void main(void)
{
int a,b,c=0,d=6,in;
bar();
for(b=0;b<4;b++)
   {
   for(a=0;a<4;a++)
      {
      do{
      gotoxy(30+c,b+d);
      in=getche();
      }while(in!='0'&&in!='1'&&in!='x'&&in!='X');
      if(in=='X'||in=='x'){in='1';table[b][a].dc=1;}
      table[b][a].input(in);
      c=c+6;
      }
   c=0;d=d+1;
   }
   scan();
   gotoxy(25,17);
   if(strcmp(ans," ")==0)strcpy(ans,"0");
   cout<<"F="<<ans;
   getche();
}


void bar(void)
{
int a,b,c=0,d=6;
clrscr();
for(a=0;a<5;a++)
   {
   for(b=0;b<9;b++)
      {
	gotoxy(27+c,b+5);
	printf("%c",179);
      }
   c=c+6;
   }
c=0;
for(a=0;a<5;a++)
   {
   for(b=0;b<25;b++)
      {
       gotoxy(27+b,d-1);
       printf("-");
      }
   c=c+6;d=d+2;
   }
gotoxy(29,4);cout<<"00";gotoxy(24,6);cout<<"00";
gotoxy(35,4);cout<<"01";gotoxy(24,8);cout<<"01";
gotoxy(41,4);cout<<"11";gotoxy(24,10);cout<<"11";
gotoxy(47,4);cout<<"10";gotoxy(24,12);cout<<"10";
for(b=0;b<3;b++)
      {
	gotoxy(53,b+8);
	printf("%c",179);
	gotoxy(22,b+10);
	printf("%c",179);

      }
for(b=0;b<12;b++)
   {
   gotoxy(b+40,3);
   printf("-");gotoxy(b+33,14);printf("-");
   }
gotoxy(45,2);cout<<"C";
gotoxy(39,15);cout<<"D";
gotoxy(19,11);cout<<"A";
gotoxy(55,9);cout<<"B";
}

int scan(void)
{
int r;char an1[100],an2[100];
r=scan16();if(r==0){return 0;}
scan8();
scan4l();
scan4();
scan2();
scan1();
strcpy(an1,ans);
side();//side one left
//second time
g=0;
for(int b=0;b<4;b++)
   for(int a=0;a<4;a++)
       table[b][a].count=0;
r=scan16();if(r==0){return 0;}
scan8();
scan4();
scan4l();
scan2();
scan1();
side();//side2 right
strcpy(an2,ans);
if(len(an2)<len(an1))strcpy(ans,an2);
if(len(an2)>len(an1))strcpy(ans,an1);
//if(len(an2)==len(an1))
//  {
   gotoxy(25,18);cout<<"F1="<<an1;
   gotoxy(25,19);cout<<"F2="<<an2;
//  }
return 0;
}


int scan16(void)
{
int a,b,r=0,p=0;
strcpy(ans," ");
for(b=0;b<4;b++)
   for(a=0;a<4;a++)
      {
      if(table[1][1].state!=table[b][a].state)
	{r=1;return r;}
      if(table[b][a].dc==0)p=1;
      }
if(p==1)if(table[1][1].state=='1')strcat(ans,"1");
if(p==0)if(table[1][1].state=='1')strcat(ans,"0");
if(table[1][1].state=='0')strcat(ans,"0");
return r;
}

int scan8(void)
{
int a,b,c=0,r=1,p=0;
strcpy(ans," ");
for(b=0;b<4;b++)
   {
   for(a=0;a<4;a++)
      {
      c=b+1;
      if(b==3)c=0;
      if(table[b][a].state!=table[c][a].state || table[b][a].state!='1')
	{r=0;break;}
      if(table[b][a].dc==0&&table[c][a].dc==0)p=1;
      }
   if(p==1 && b==0 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"A'");group8(b,1,++g);}
   if(p==1 && b==1 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"B");group8(b,1,++g); }
   if(p==1 && b==2 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"A");group8(b,1,++g); }
   if(p==1 && b==3 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"B'");group8(b,1,++g);}
   r=1;p=0;
   }
r=1;c=0;p=0;
for(b=0;b<4;b++)
   {
   for(a=0;a<4;a++)
      {
      c=b+1;
      if(b==3)c=0;
      if(table[b][a].state!=table[c][a].state || table[b][a].state!='1')
	{r=0;break;}
      if((table[b][a].dc==0&&table[b][a].count==0)||(table[c][a].dc==0&&table[c][a].count==0))p=1;
      }
   if(p==1 && b==0 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"A'");group8(b,1,++g);}
   if(p==1 && b==1 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"B");group8(b,1,++g); }
   if(p==1 && b==2 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"A");group8(b,1,++g); }
   if(p==1 && b==3 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"B'");group8(b,1,++g);}
   r=1;p=0;
   }
r=1;c=0;p=0;
for(b=0;b<4;b++)
   {
   for(a=0;a<4;a++)
      {
      c=b+1;
      if(b==3){c=0;}
      if(table[a][b].state!=table[a][c].state || table[a][b].state!='1')
	{r=0;break;}
      if(table[a][b].dc==0&&table[a][c ].dc==0)p=1;
      }
   if(p==1 && b==0 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"C'");group8(b,0,++g);}
   if(p==1 && b==1 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"D");group8(b,0,++g); }
   if(p==1 && b==2 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"C");group8(b,0,++g); }
   if(p==1 && b==3 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"D'");group8(b,0,++g);}
   r=1;p=0;
   }
r=1;c=0;p=0;
for(b=0;b<4;b++)
   {
   for(a=0;a<4;a++)
      {
      c=b+1;
      if(b==3){c=0;}
      if(table[a][b].state!=table[a][c].state || table[a][b].state!='1')
	{r=0;break;}
      if((table[a][b].dc==0&&table[a][b].count==0)||(table[a][c].dc==0&&table[a][c].count==0))p=1;
      }
   if(p==1 && b==0 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"C'");group8(b,0,++g);}
   if(p==1 && b==1 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"D");group8(b,0,++g); }
   if(p==1 && b==2 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"C");group8(b,0,++g); }
   if(p==1 && b==3 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"D'");group8(b,0,++g);}
   r=1;p=0;
   }
return 0;
}

void group8(int z,int ax,int code)
{
int a,b,c,d;
if(ax==1)//y axis
  {
  for(a=0;a<4;a++)
     {
     d=z+1;
     if(z==3){d=0;}
     table[z][a].ingroup(code);
     table[d][a].ingroup(code);
     }
  }
if(ax==0)// x axis
  {
  for(a=0;a<4;a++)
     {
     d=z+1;
     if(z==3){d=0;}
     table[a][z].ingroup(code);
     table[a][d].ingroup(code);
     }
   }
}

int scan4l(void)
{
int a,b,c=0,r=1,p=1;
for(b=0;b<4;b++)
   {
   for(a=0;a<3;a++)
      {
      if(table[a][b].state!=table[a+1][b].state || table[a][b].state!='1')
	{r=0;break;}
      if(table[a][b].count!=0||table[a+1][b].count!=0)p=0;
      if(r!=0)if(table[a][b].dc==0||table[a+1][b].dc==0)c=1;
      }
   if(c==1 && p==1 && b==0 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"C'D'");group4l(b,1,++g);}
   if(c==1 && p==1 && b==1 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"C'D");group4l(b,1,++g);}
   if(c==1 && p==1 && b==2 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"CD");group4l(b,1,++g);}
   if(c==1 && p==1 && b==3 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"CD'");group4l(b,1,++g);}
   c=0;r=1;p=1;
   }
p=1;c=0;r=1;
for(b=0;b<4;b++)
   {
   for(a=0;a<3;a++)
      {
      if(table[b][a].state!=table[b][a+1].state || table[b][a].state!='1')
	{r=0;break;}
      if(table[b][a].count!=0||table[b][a+1].count!=0)p=0;
      if(table[b][a].dc==0||table[b][a+1].dc==0)c=1;
       }
   if(c==1 && p==1 && b==0 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"A'B'");group4l(b,0,++g);}
   if(c==1 && p==1 && b==1 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"A'B");group4l(b,0,++g);}
   if(c==1 && p==1 && b==2 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"AB");group4l(b,0,++g);}
   if(c==1 && p==1 && b==3 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"AB'");group4l(b,0,++g);}
   c=0;r=1;p=1;
   }
r=1;c=0;p=0;
for(b=0;b<4;b++)
   {
   for(a=0;a<3;a++)
      {
      if(table[a][b].state!=table[a+1][b].state || table[a][b].state!='1')
	{r=0;break;}
      if((table[a][b].dc==0&&table[a][b].count==0)||(table[a+1][b].count==0&&table[a+1][b].dc==0))p=1;
      if(r!=0)if(table[a][b].dc==0||table[a+1][b].dc==0)c=1;
      }
   if(c==1 && p==1 && b==0 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"C'D'");group4l(b,1,++g);}
   if(c==1 && p==1 && b==1 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"C'D");group4l(b,1,++g);}
   if(c==1 && p==1 && b==2 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"CD");group4l(b,1,++g);}
   if(c==1 && p==1 && b==3 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"CD'");group4l(b,1,++g);}
   c=0;r=1;p=0;
   }
r=1;c=0;p=0;
for(b=0;b<4;b++)
   {
   for(a=0;a<3;a++)
      {
      if(table[b][a].state!=table[b][a+1].state || table[b][a].state!='1')
	{r=0;break;}
      if((table[b][a].dc==0&&table[b][a].count==0)||(table[b][a+1].count==0&&table[b][a+1].dc==0))p=1;
      if(table[b][a].dc==0||table[b][a+1].dc==0)c=1;
       }
   if(c==1 && p==1 && b==0 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"A'B'");group4l(b,0,++g);}
   if(c==1 && p==1 && b==1 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"A'B");group4l(b,0,++g);}
   if(c==1 && p==1 && b==2 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"AB");group4l(b,0,++g);}
   if(c==1 && p==1 && b==3 && r==1 ){if(strcmp(ans," ")!=0)strcat(ans,"+");strcat(ans,"AB'");group4l(b,0,++g);}
   c=0;r=1;p=0;
   }
return 0;
}


int group4l(int b,int ax,int code)
{
if(ax==0)
{
for(int a=0;a<4;a++)
   {
   table[b][a].ingroup(code);
   }
}
if(ax==1)
{
for(int a=0;a<4;a++)
   {
   table[a][b].ingroup(code);
   }
}
return 0;
}



int scan4(void)
{
int a,b,c,d,f,e,h,r=1,q=0,p=0,con=0;
 for(h=4;h>0;h--)
for(c=0;c<4;c++)
   for(b=0;b<4;b++)
      {
      for(a=0;a<2;a++)
	 {e=f=a+b;d=c+1;
	 if(c==3)d=0;
	 if(b==3 && a==1){f=0;e=0;}
	 if(table[e][c].state!=table[f][d].state || table[e][c].state!='1'||table[f][d].state!='1')r=0;
	 if(r!=0)if(table[e][c].state=='1'&&table[e][c].dc==0)con=con+1;
	 if(r!=0)if(table[f][d].state=='1'&&table[f][d].dc==0)con=con+1;
	 if(table[e][c].dc==0||table[f][d].dc==0)p=1;
	 if((table[e][c].dc==0 && table[e][c].count==0 &&table[e][c].state=='1')||(table[f][d].dc==0&&table[f][d].count==0 &&table[f][d].state=='1'))q=1;
	 }
      if(con==h && p==1 && q==1 && b==0 && r==1 && c==0 && group4(b,c,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'C'");}else strcpy(ans,"A'C'");}
      if(con==h && p==1 && q==1 && b==1 && r==1 && c==0 && group4(b,c,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"BC'");}else strcpy(ans,"BC'");}
      if(con==h && p==1 && q==1 && b==2 && r==1 && c==0 && group4(b,c,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AC'");}else strcpy(ans,"AC'");}
      if(con==h && p==1 && q==1 && b==3 && r==1 && c==0 && group4(b,c,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"B'C'");}else strcpy(ans,"B'C'");}
      if(con==h && p==1 && q==1 && b==0 && r==1 && c==1 && group4(b,c,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'D");}else strcpy(ans,"A'D");}
      if(con==h && p==1 && q==1 && b==1 && r==1 && c==1 && group4(b,c,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"BD");}else strcpy(ans,"BD");}
      if(con==h && p==1 && q==1 && b==2 && r==1 && c==1 && group4(b,c,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AD");}else strcpy(ans,"AD");}
      if(con==h && p==1 && q==1 && b==3 && r==1 && c==1 && group4(b,c,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"B'D");}else strcpy(ans,"B'D");}
      if(con==h && p==1 && q==1 && b==0 && r==1 && c==2 && group4(b,c,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'C");}else strcpy(ans,"A'C");}
      if(con==h && p==1 && q==1 && b==1 && r==1 && c==2 && group4(b,c,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"BC");}else strcpy(ans,"BC");}
      if(con==h && p==1 && q==1 && b==2 && r==1 && c==2 && group4(b,c,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AC");}else strcpy(ans,"AC");}
      if(con==h && p==1 && q==1 && b==3 && r==1 && c==2 && group4(b,c,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"B'C");}else strcpy(ans,"B'C");}
      if(con==h && p==1 && q==1 && b==0 && r==1 && c==3 && group4(b,c,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'D'");}else strcpy(ans,"A'D'");}
      if(con==h && p==1 && q==1 && b==1 && r==1 && c==3 && group4(b,c,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"BD'");}else strcpy(ans,"BD'");}
      if(con==h && p==1 && q==1 && b==2 && r==1 && c==3 && group4(b,c,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AD'");}else strcpy(ans,"AD'");}
      if(con==h && p==1 && q==1 && b==3 && r==1 && c==3 && group4(b,c,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"B'D'");}else strcpy(ans,"B'D'");}
      r=1;q=0;p=0;con=0;
      }
return 0;
}

int group4(int b,int c,int code)
{
int d,f;
f=c+1;if(c==3){f=0;}
int a1=table[b][c].comp(table[b][f]);
d=b+1;if(b==3){d=0;}
int a2=table[d][c].comp(table[d][f]);
d=b+1;if(b==3){d=0;}
f=c+1;if(c==3){f=0;}
int a3=table[b][c].comp(table[d][f]);
int a4=table[d][c].comp(table[b][f]);
if(a1==a2==a3==a4 && a1!=0){return 0;}
table[b][c].ingroup(code);
f=c+1;if(c==3){f=0;}
table[b][f].ingroup(code);
d=b+1;if(b==3){d=0;}
table[d][c].ingroup(code);
table[d][f].ingroup(code);
return 1;
}

int scan2(void)
{
int a,b,c,d,f,e,r=1;
for(c=0;c<4;c++)
   for(b=0;b<4;b++)
      {
      d=b+1;if(b==3)d=0;
      if(table[b][c].state!=table[d][c].state ||(table[b][c].state!='1'&&table[d][c].state!='1'))r=0;
      if(table[b][c].dc==1&&table[d][c].dc==1)r=0;
      if(table[b][c].dc==0&&table[d][c].dc==0&&table[b][c].count==0&&table[d][c].count==0){
      if(c==0 && b==0 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans," A'C'D'");}else strcpy(ans,"A'C'D'");}
      if(c==0 && b==1 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"BC'D'");}else strcpy(ans,"BC'D'");}
      if(c==0 && b==2 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AC'D'");}else strcpy(ans,"AC'D'");}
      if(c==0 && b==3 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"B'C'D'");}else strcpy(ans,"B'C'D'");}
      if(c==1 && b==0 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'C'D");}else strcpy(ans,"A'C'D");}
      if(c==1 && b==1 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"BC'D");}else strcpy(ans,"BC'D");}
      if(c==1 && b==2 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AC'D");}else strcpy(ans,"AC'D");}
      if(c==1 && b==3 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"B'C'D");}else strcpy(ans,"B'C'D");}
      if(c==2 && b==0 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'CD");}else strcpy(ans,"A'CD");}
      if(c==2 && b==1 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"BCD");}else strcpy(ans,"BCD");}
      if(c==2 && b==2 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ACD");}else strcpy(ans,"ACD");}
      if(c==2 && b==3 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"B'CD");}else strcpy(ans,"B'CD");}
      if(c==3 && b==0 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'CD'");}else strcpy(ans,"A'CD'");}
      if(c==3 && b==1 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"BCD'");}else strcpy(ans,"BCD'");}
      if(c==3 && b==2 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ACD'");}else strcpy(ans,"ACD'");}
      if(c==3 && b==3 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"B'CD'");}else strcpy(ans,"B'CD'");}}
      r=1;
     }
r=1;

for(c=0;c<4;c++)
   for(b=0;b<4;b++)
      {
      d=c+1;if(c==3)d=0;
      if(table[b][c].state!=table[b][d].state || (table[b][c].state!='1'&&table[b][d].state!='1'))r=0;
      if(table[b][c].dc==1&&table[b][d].dc==1)r=0;
      if(table[b][c].dc==0&&table[b][d].dc==0&&table[b][c].count==0&&table[b][d].count==0){
      if(c==0 && b==0 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'B'C'");}else strcpy(ans,"A'B'C'");}
      if(c==0 && b==1 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'BC'");}else strcpy(ans,"A'BC'");}
      if(c==0 && b==2 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ABC'");}else strcpy(ans,"ABC'");}
      if(c==0 && b==4 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AB'C'");}else strcpy(ans,"AB'C'");}
      if(c==1 && b==0 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'B'D");}else strcpy(ans,"A'B'D");}
      if(c==1 && b==1 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'BD");}else strcpy(ans,"A'BD");}
      if(c==1 && b==2 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ABD");}else strcpy(ans,"ABD");}
      if(c==1 && b==3 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AB'D");}else strcpy(ans,"AB'D");}
      if(c==2 && b==0 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'B'C");}else strcpy(ans,"A'B'C");}
      if(c==2 && b==1 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'BC");}else strcpy(ans,"A'BC");}
      if(c==2 && b==2 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ABC");}else strcpy(ans,"ABC");}
      if(c==2 && b==3 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AB'C");}else strcpy(ans,"AB'C'");}
      if(c==3 && b==0 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'B'D");}else strcpy(ans,"A'B'D");}
      if(c==3 && b==1 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'BD'");}else strcpy(ans,"A'BD'");}
      if(c==3 && b==2 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ABD'");}else strcpy(ans,"ABD'");}
      if(c==3 && b==3 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AB'D'");}else strcpy(ans,"AB'D'");}}
      r=1;
    }
   r=1;
for(c=0;c<4;c++)
   for(b=0;b<4;b++)
      {
      d=c+1;if(c==3)d=0;
      if(table[b][c].state!=table[b][d].state || (table[b][c].state!='1'&&table[b][d].state!='1'))r=0;
      if(table[b][c].dc==1&&table[b][d].dc==1)r=0;
      if((table[b][c].dc==0&&table[b][d].dc==0)&&(table[b][c].count==0||table[b][d].count==0)){
      if(c==0 && b==0 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'B'C'");}else strcpy(ans,"A'B'C'");}
      if(c==0 && b==1 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'BC'");}else strcpy(ans,"A'BC'");}
      if(c==0 && b==2 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ABC'");}else strcpy(ans,"ABC'");}
      if(c==0 && b==4 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AB'C'");}else strcpy(ans,"AB'C'");}
      if(c==1 && b==0 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'B'D");}else strcpy(ans,"A'B'D");}
      if(c==1 && b==1 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'BD");}else strcpy(ans,"A'BD");}
      if(c==1 && b==2 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ABD");}else strcpy(ans,"ABD");}
      if(c==1 && b==3 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AB'D");}else strcpy(ans,"AB'D");}
      if(c==2 && b==0 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'B'C");}else strcpy(ans,"A'B'C");}
      if(c==2 && b==1 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'BC");}else strcpy(ans,"A'BC");}
      if(c==2 && b==2 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ABC");}else strcpy(ans,"ABC");}
      if(c==2 && b==3 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AB'C");}else strcpy(ans,"AB'C'");}
      if(c==3 && b==0 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'B'D");}else strcpy(ans,"A'B'D");}
      if(c==3 && b==1 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'BD'");}else strcpy(ans,"A'BD'");}
      if(c==3 && b==2 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ABD'");}else strcpy(ans,"ABD'");}
      if(c==3 && b==3 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AB'D'");}else strcpy(ans,"AB'D'");}}
      r=1;
    }
   r=1;
for(c=0;c<4;c++)
   for(b=0;b<4;b++)
      {
      d=b+1;if(b==3)d=0;
      if(table[b][c].state!=table[d][c].state ||(table[b][c].state!='1'&&table[d][c].state!='1'))r=0;
      if(table[b][c].dc==1&&table[d][c].dc==1)r=0;
      if((table[b][c].dc==0&&table[d][c].dc==0)&&(table[b][c].count==0||table[d][c].count==0)){
      if(c==0 && b==0 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans," A'C'D'");}else strcpy(ans,"A'C'D'");}
      if(c==0 && b==1 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"BC'D'");}else strcpy(ans,"BC'D'");}
      if(c==0 && b==2 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AC'D'");}else strcpy(ans,"AC'D'");}
      if(c==0 && b==3 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"B'C'D'");}else strcpy(ans,"B'C'D'");}
      if(c==1 && b==0 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'C'D");}else strcpy(ans,"A'C'D");}
      if(c==1 && b==1 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"BC'D");}else strcpy(ans,"BC'D");}
      if(c==1 && b==2 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AC'D");}else strcpy(ans,"AC'D");}
      if(c==1 && b==3 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"B'C'D");}else strcpy(ans,"B'C'D");}
      if(c==2 && b==0 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'CD");}else strcpy(ans,"A'CD");}
      if(c==2 && b==1 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"BCD");}else strcpy(ans,"BCD");}
      if(c==2 && b==2 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ACD");}else strcpy(ans,"ACD");}
      if(c==2 && b==3 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"B'CD");}else strcpy(ans,"B'CD");}
      if(c==3 && b==0 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'CD'");}else strcpy(ans,"A'CD'");}
      if(c==3 && b==1 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"BCD'");}else strcpy(ans,"BCD'");}
      if(c==3 && b==2 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ACD'");}else strcpy(ans,"ACD'");}
      if(c==3 && b==3 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"B'CD'");}else strcpy(ans,"B'CD'");}}
      r=1;
     }
r=1;
for(c=0;c<4;c++)
   for(b=0;b<4;b++)
      {
      d=b+1;if(b==3)d=0;
      if(table[b][c].state!=table[d][c].state ||(table[b][c].state!='1'&&table[d][c].state!='1'))r=0;
      if(table[b][c].dc==1&&table[d][c].dc==1)r=0;
      if((table[b][c].state=='1'&&table[b][c].count==0&&table[b][c].dc==0)||(table[d][c].state=='1'&&table[d][c].count==0&&table[d][c].dc==0)){
      if(c==0 && b==0 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans," A'C'D'");}else strcpy(ans,"A'C'D'");}
      if(c==0 && b==1 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"BC'D'");}else strcpy(ans,"BC'D'");}
      if(c==0 && b==2 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AC'D'");}else strcpy(ans,"AC'D'");}
      if(c==0 && b==3 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"B'C'D'");}else strcpy(ans,"B'C'D'");}
      if(c==1 && b==0 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'C'D");}else strcpy(ans,"A'C'D");}
      if(c==1 && b==1 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"BC'D");}else strcpy(ans,"BC'D");}
      if(c==1 && b==2 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AC'D");}else strcpy(ans,"AC'D");}
      if(c==1 && b==3 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"B'C'D");}else strcpy(ans,"B'C'D");}
      if(c==2 && b==0 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'CD");}else strcpy(ans,"A'CD");}
      if(c==2 && b==1 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"BCD");}else strcpy(ans,"BCD");}
      if(c==2 && b==2 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ACD");}else strcpy(ans,"ACD");}
      if(c==2 && b==3 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"B'CD");}else strcpy(ans,"B'CD");}
      if(c==3 && b==0 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'CD'");}else strcpy(ans,"A'CD'");}
      if(c==3 && b==1 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"BCD'");}else strcpy(ans,"BCD'");}
      if(c==3 && b==2 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ACD'");}else strcpy(ans,"ACD'");}
      if(c==3 && b==3 && r==1 && group2(b,c,0,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"B'CD'");}else strcpy(ans,"B'CD'");}}
      r=1;
     }
   r=1;
for(c=0;c<4;c++)
   for(b=0;b<4;b++)
      {
      d=c+1;if(c==3)d=0;
      if(table[b][c].state!=table[b][d].state || (table[b][c].state!='1'&&table[b][d].state!='1'))r=0;
      if(table[b][c].dc==1&&table[b][d].dc==1)r=0;
      if((table[b][c].state=='1'&&table[b][c].count==0&&table[b][c].dc==0)||(table[b][d].state=='1'&&table[b][d].count==0&&table[b][d].dc==0)){
      if(c==0 && b==0 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'B'C'");}else strcpy(ans,"A'B'C'");}
      if(c==0 && b==1 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'BC'");}else strcpy(ans,"A'BC'");}
      if(c==0 && b==2 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ABC'");}else strcpy(ans,"ABC'");}
      if(c==0 && b==4 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AB'C'");}else strcpy(ans,"AB'C'");}
      if(c==1 && b==0 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'B'D");}else strcpy(ans,"A'B'D");}
      if(c==1 && b==1 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'BD");}else strcpy(ans,"A'BD");}
      if(c==1 && b==2 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ABD");}else strcpy(ans,"ABD");}
      if(c==1 && b==3 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AB'D");}else strcpy(ans,"AB'D");}
      if(c==2 && b==0 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'B'C");}else strcpy(ans,"A'B'C");}
      if(c==2 && b==1 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'BC");}else strcpy(ans,"A'BC");}
      if(c==2 && b==2 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ABC");}else strcpy(ans,"ABC");}
      if(c==2 && b==3 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AB'C");}else strcpy(ans,"AB'C'");}
      if(c==3 && b==0 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'B'D");}else strcpy(ans,"A'B'D");}
      if(c==3 && b==1 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'BD'");}else strcpy(ans,"A'BD'");}
      if(c==3 && b==2 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ABD'");}else strcpy(ans,"ABD'");}
      if(c==3 && b==3 && r==1&& group2(b,c,1,++g)!=0){if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AB'D'");}else strcpy(ans,"AB'D'");}}
      r=1;
    }

return 0;
}




int group2(int b ,int c,int ax ,int code)
{
if(ax==1)
  {
  int d=c+1;
  if(c==3)d=0;
 if((table[b][c].count==0&&table[b][c].dc==0) ||(table[b][d].count==0&&table[b][d].dc==0) && table[b][c].comp(table[b][d])==0 &&(table[b][d].state=='1'&& table[b][c].state=='1'))
    {
    table[b][c].ingroup(code);
    table[b][d].ingroup(code);
    return 1;
    }
  }
if(ax==0)
  {
  int f=b+1;
  if(b==3)f=0;
  if((table[b][c].count==0&&table[b][c].dc==0) ||(table[f][c].count==0&&table[f][c].dc==0) && table[b][c].comp(table[f][c])==0 &&(table[b][c].state=='1'&& table[f][c].state=='1'))
    {
    table[b][c].ingroup(code);
    table[f][c].ingroup(code);
    return 1;
    }
   }
return 0;
}





int scan1(void)
{
for(int b=0;b<4;b++)
   {
   for(int a=0;a<4;a++)
      {
      if(table[b][a].count==0 && table[b][a].state=='1'&&table[b][a].dc==0)
	{
	if(b==0&&a==0)if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'B'C'D'");}else strcpy(ans,"A'B'C'D'");
	if(b==0&&a==1)if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'B'C'D");}else strcpy(ans,"A'B'C'D");
	if(b==0&&a==2)if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'B'CD");}else strcpy(ans,"A'B'CD");
	if(b==0&&a==3)if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'B'CD'");}else strcpy(ans,"A'B'CD'");
	if(b==1&&a==0)if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'BC'D'");}else strcpy(ans,"A'BC'D'");
	if(b==1&&a==1)if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'BC'D");}else strcpy(ans,"A'BC'D");
	if(b==1&&a==2)if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'BCD");}else strcpy(ans,"A'BCD");
	if(b==1&&a==3)if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"A'BCD'");}else strcpy(ans,"A'BCD'");
	if(b==2&&a==0)if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ABC'D'");}else strcpy(ans,"ABC'D");
	if(b==2&&a==1)if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ABCD'");}else strcpy(ans,"ABCD'");
	if(b==2&&a==2)if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ABCD");}else strcpy(ans,"ABCD");
	if(b==2&&a==3)if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"ABC'D");}else strcpy(ans,"ABC'D");
	if(b==3&&a==0)if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AB'C'D'");}else strcpy(ans,"AB'C'D'");
	if(b==3&&a==1)if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AB'C'D");}else strcpy(ans,"AB'C'D");
	if(b==3&&a==2)if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AB'CD");}else strcpy(ans,"AB'CD");
	if(b==3&&a==3)if(strcmp(ans," ")!=0){strcat(ans,"+");strcat(ans,"AB'CD'");}else strcpy(ans,"AB'CD'");
	}
      }
   }
return 0;
}
int len(char *a)
{
int c=0;
for(int b=0;b<strlen(a)+1;b++)
{
if(a[b]=='A'||a[b]=='B'||a[b]=='C'||a[b]=='D')c++;
}
return c;
}

void side(void)
{
int c=2,a,b;
   if(x==0){gotoxy(4,1);cprintf("F1");}
   if(x==65){gotoxy(4+x,1);cprintf("F2");}
   for(a=0;a<4;a++)
      {
      for(b=0;b<4;b++)
	 {
	 gotoxy(1+x,c++);
	 cprintf("%d%d ",a,b);table[a][b].showg();//printf("\n");
	 }c++;
      }x=65;
}