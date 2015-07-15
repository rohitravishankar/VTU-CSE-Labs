#include<stdio.h>
#include<stdlib.h>
void main()
{
	int ch1,ch2;  
	FILE *fp1=fopen("studentname.txt","r"); 
	FILE *fp2=fopen("usn.txt","r");
	FILE *fp3=fopen("output.txt","w");
	if(fp1==NULL || fp2==NULL)  
	{
		printf("Cannot open requested file\n");
		exit(0);
	}
	fprintf(fp3,"Student name\tUSN\n"); 
	ch1=fgetc(fp1); 
	ch2=fgetc(fp2);
	while(ch1 != EOF || ch2 != EOF) 
	{
			while(ch1 != '\n') 
			{
				fputc(ch1,fp3); 
				ch1=fgetc(fp1); 
			}
			ch1=fgetc(fp1);
			fputc(' ',fp3); 
			fputc('\t',fp3); 
			while(ch2 != '\n') 
			{
				fputc(ch2,fp3);
				ch2=fgetc(fp2);
			}
			ch2=fgetc(fp2);
			fputc('\n',fp3
	}
	printf("Please Open file output.txt\n");
	fclose(fp1); // closing all files "THIS IS A MUST"
	fclose(fp2);
	fclose(fp3);
}
