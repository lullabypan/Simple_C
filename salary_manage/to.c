#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>


void input();
void xianshi();
void xiugai();
void chazhao();
void shanchu();
void tongji();

struct worker
{
  int id;
  char name[12];
  float jben;
  float zwu;
  float jtie;
  float bxian;
  float gjjing;
  float total;
  struct worker *next;
};



int main()
{
	int x,flag=0;
	system("color F1");
    printf("\n*****************************��ӭ����ְ�����ʹ���ϵͳ**************************\n");
	while(flag==0)
	{
	   printf("\n-------------------��ѡ�������Ŀ:\n\n");
	   printf("-----�����¼:�밴1\n");
       printf("-----��ʾ��¼:�밴2\n");
       printf("-----�޸ļ�¼:�밴3\n");
       printf("-----���Ҽ�¼:�밴4\n");
       printf("-----ɾ����¼:�밴5\n");
	   printf("-----ͳ������:�밴6\n");
	   printf("------------------������:");
	   scanf("%d",&x);
	   switch(x)
	   {
	    case 1:input();break;
	    case 2:xianshi();break;
	    case 3:xiugai();break;
		case 4:chazhao();break;
		case 5:shanchu();break;
		case 6:tongji();break;
	    default:break;
	}
	   printf("(0)��������   (1)������в���  \n������:");
	   scanf("%d",&flag);

	}

	return 0;
}




void input()
{
   int i=0,n,flag;
   struct worker *head,*phead,*ptail;
  
   FILE *fp;
   printf("(1)�����µ�Ա��������Ϣ�ļ�     (2)���Ա��������Ϣ\n-----��ѡ��:");
	   scanf("%d",&flag);
if(flag==1)
{
   fp=fopen("salary.dat","wb");
}
if(flag==2)
{
   fp=fopen("salary.dat","ab");
}
   printf("������ְ����:");
   scanf("%d",&n);
  printf("��������صĹ�����Ϣ:\nid ���� | �������� | ְ���� | ��λ���� | ҽ�Ʊ��� | ������ | �ܹ���\n");
   head=phead=ptail=(struct worker *)malloc(sizeof(struct worker));  
   scanf("%d%s%f%f%f%f%f%f",&phead->id,&phead->name,&phead->jben,&phead->zwu,&phead->jtie,&phead->bxian,&phead->gjjing,&phead->total);
   fwrite(phead,sizeof(struct worker),1,fp);
   
       head=phead;
       phead->next=NULL;
       
   for(i=1;i<n;i++)
   {   
       ptail=phead;
       phead=(struct worker*)malloc(sizeof(struct worker));
	   scanf("%d%s%f%f%f%f%f%f",&phead->id,&phead->name,&phead->jben,&phead->zwu,&phead->jtie,&phead->bxian,&phead->gjjing,&phead->total);
        fwrite(phead,sizeof(struct worker),1,fp);
	   ptail->next=phead;
       phead->next=NULL;
       
   }
   
  fclose(fp);
	  
}


void xianshi()
{
   struct worker a;
   int n,i,x,flag2=0;
   float v;
   FILE *fp;
   printf("\n���������Ա����:");
   scanf("%d",&n);
   
   for(i=0;i<n;i++)
   {    

	   printf("\n������Ա��ID:");
	   scanf("%d",&x);
       fp=fopen("salary.dat","rb");
       fread(&a,sizeof(struct worker),1,fp);
	   while(!feof(fp))
	   {
		   
	       if(x==a.id)
		   {  
			   v=a.total/5;
		      printf("����:%s\t��������:%.1f\tְ����:%.1f\t��λ����:%.1f\nҽ�Ʊ���:%.1f\t������:%.1f\t�ܹ���:%.1f\tƽ������:%.1f\n",a.name,a.jben,a.zwu,a.jtie,a.bxian,a.gjjing,a.total,v);
			  flag2=1;
		   }
        fread(&a,sizeof(struct worker),1,fp);
	   }
   }
   if(flag2==0)
   {
      printf("���޴���!!!\n");
   }
   fclose(fp);
}


void xiugai()
{

    struct worker a;
    int ID,i,flag3=0,l;
	char name2[12]="chushi";
	FILE *fp;
	
	while(flag3==0)
	{
        fp=fopen("salary.dat","ab+");
		printf("��������Ҫ�޸����ݵ�Ա��id:");
	    scanf("%d",&ID);
		 fread(&a,sizeof(struct worker),1,fp);
        while(!feof(fp))
		{
		   
	       if(ID==a.id)
		   {  
		      printf("��ǰ��Ϣ����:\n����:%s\t��������:%.1f\tְ����:%.1f\t��λ����:%.1f\nҽ�Ʊ���:%.1f\t������:%.1f\t�ܹ���:%.1f\n",a.name,a.jben,a.zwu,a.jtie,a.bxian,a.gjjing,a.total);
              printf("\n(1)����**(2)�������� **(3)ְ����**(4)��λ����**(5)ҽ�Ʊ���**(6)������**(7)�ܹ���\n��������Ҫ�޸ĵ���Ŀ�������Ӧ��ţ�:");
	          scanf("%d",&i);
			  printf("�������޸�Ϊ:");
			  if(i==1)
			  {
			     scanf("%s",&a.name);
                  l=strlen(a.name);
                  fwrite(&a.name,sizeof((char*)l),1,fp);  
			  }
			  else if(i==2)
			  {
			    scanf("%f",&a.jben);
               fwrite(&a.name,sizeof(a.name),1,fp); 
			  }
               else if(i==3)
			  {
			    scanf("%f",&a.zwu);
               fwrite(&a.zwu,sizeof(float),1,fp); 
			  }
			  else if(i==4)
			  {
			    scanf("%f",&a.jtie);
                fwrite(&a.jtie,sizeof(float),1,fp); 
			  }
             else if(i==5)
			  {
			    scanf("%f",&a.bxian);
                fwrite(&a.bxian,sizeof(float),1,fp); 
			  }
              else if(i==6)
			  {
			    scanf("%f",&a.gjjing);
                fwrite(&a.gjjing,sizeof(float),1,fp); 
			  }
			  a.total=a.jben+a.zwu+a.jtie+a.bxian+a.gjjing;
			  fwrite(&a.total,sizeof(float),1,fp);
              printf("�޸����,����Ϣ����:\n����:%s\t��������:%.1f\tְ����:%.1f\t��λ����:%.1f\nҽ�Ʊ���:%.1f\t������:%.1f\t�ܹ���:%.1f\n",a.name,a.jben,a.zwu,a.jtie,a.bxian,a.gjjing,a.total);  
		   }
        fread(&a,sizeof(struct worker),1,fp);
	   }
       printf("�޸����,������1:     �����޸�,������0:\n------������:");
	   scanf("%d",&flag3);
       fclose(fp);
	 }
}

void chazhao()
{
   float x,flag=0;
   struct worker a;
   FILE *fp;
   printf("�������������:");
   scanf("%f",&x);
   
   fp=fopen("salary.dat","rb");
    fread(&a,sizeof(struct worker),1,fp);
   while(!feof(fp))
   {
       
	   if(a.jben==x||a.bxian==x||a.gjjing==x||a.jtie==x||a.zwu==0||a.total==0)
	   {
	   printf("����:%s\t��������:%.1f\tְ����:%.1f\t��λ����:%.1f\nҽ�Ʊ���:%.1f\t������:%.1f\t�ܹ���:%.1f\n",a.name,a.jben,a.zwu,a.jtie,a.bxian,a.gjjing,a.total);
	   flag=1;
	   }
     fread(&a,sizeof(struct worker),1,fp);
   }
   if(flag==0)
   {
   printf("------û���ҵ�������------!!!!!\n");
   }
   fclose(fp);
}


void shanchu()
{
    int x;
	
    struct worker a;
	FILE *fp,*fp1;
	fp=fopen("salary.dat","rb");
	fp1=fopen("new.dat","wb+");
	printf("��������Ҫɾ���Ķ���ID:");
	printf("ID:");
	scanf("%d",&x);
    fread(&a,sizeof(struct worker),1,fp);
    while(!feof(fp))
	{
		if(a.id==x)
		{
		
		}
		else
		{
		  fwrite(&a,sizeof(struct worker),1,fp1);
		}
	   fread(&a,sizeof(struct worker),1,fp);
	}
    fclose(fp);
	fseek(fp1,0,0);
    fread(&a,sizeof(struct worker),1,fp1);
	while(!feof(fp1))
	{
     printf("��Ϣ����:\n����:%s\t��������:%.1f\tְ����:%.1f\t��λ����:%.1f\nҽ�Ʊ���:%.1f\t������:%.1f\t�ܹ���:%.1f\n",a.name,a.jben,a.zwu,a.jtie,a.bxian,a.gjjing,a.total);
	 fread(&a,sizeof(struct worker),1,fp1);
	}
    fclose(fp1);
	remove("salary.dat");
	rename("new.dat","salary.dat");
    
 
}

void tongji()
{
  float x1=0,x2=0,x3=0,x4=0,x5=0,x6=0,sum=0;
  int i=0,y1=0,y2=0,y3=0;
   struct worker a;
   FILE *fp;
   fp=fopen("salary.dat","rb");
   printf("--------------------------------------------------------------------\n  ְ��������Ϣ����:\n");
   printf(" |id   |����    |��������|ְ����|��λ����|ҽ�Ʊ���|������  |�ܹ���  |\n");
   fread(&a,sizeof(struct worker),1,fp);
   while(!feof(fp))
   {
     
     x1+=a.jben;
	 x2+=a.zwu;
	 x3+=a.jtie;
	 x4+=a.bxian;
	 x5+=a.gjjing;
	 x6+=a.total;
	 i++;
	 if((a.jben+a.zwu+a.jtie)>3000)
	 {
	    y1++;
	 }
	 else if((a.jben+a.zwu+a.jtie)<=3000&&(a.jben+a.zwu+a.jtie)>=2000)
	 {
	   y2++;
	 }
      else if((a.jben+a.zwu+a.jtie)<2000&&(a.jben+a.zwu+a.jtie)>=1000)
	 {
	   y3++;
	 }
     printf(" |%-5d|%-8s|%-8.1f|%-8.1f|%-8.1f|%-8.1f|%-8.1f|%-8.1f|\n",a.id,a.name,a.jben,a.zwu,a.jtie,a.bxian,a.gjjing,a.total);
     fread(&a,sizeof(struct worker),1,fp);
   }
   printf("\n |����ƽ������  |%-8.1f|%-8.1f|%-8.1f|%-8.1f|%-8.1f|%-8.1f|\n",x1,x2,x3,x4,x5,x6);
   printf("\n����ǰ����֮����3000Ԫ���ϵ�ռ:%.1f%c\n����ǰ����֮����2000~3000Ԫ��ռ:%.1f%c\n����ǰ����֮����1000~2000Ԫ��ռ:%.1f%c\n-------------------------------------------------\n",y1*100.0/i,'%',y2*100.0/i,'%',y3*100.0/i,'%');
   fclose(fp);
}


/* 1 ���� 1286.0 794.0 198.0 189.0 135.0 2034.0
   2 ���� 1185.0 628.0 135.0 94.0 114.0 1740.0
   3 ��С�� 895.0 438.0 98.0 64.0 114.0 1294.0
   4 ��Ч�� 1350.0 868.0 210.0 116.0 150.0 2162.0
   5 ��ɽ 745.0 398.0 84.0 61.0 68.0 1098.0
   6 dsa 456.0 456.0 123.0 3.0 153.0 879.0
   7 ���� 1520.0 462.0 456.0 100.0 80.0 2258.0 
 */