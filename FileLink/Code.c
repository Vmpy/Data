#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{
    FILE *fp_picture,*fp_rar,*fp_new;
    char file_rar_name[50],file_picture_name[50],file_new_name[50];
    char ch = 0;
    system("color 0f");
    for(;;)
    {
        printf("         ******************欢迎使用开车神器(图片合成)BETA1.0******************         \n");
        printf("\n请输入您要修改的RAR/ZIP/7Z文件:(非本目录文件必须加路径)\n\n");
        scanf("%s",file_picture_name);                                  /*对应rar文件名字*/
        printf("\n请输入您要修改的图片文件:(非本目录文件必须加路径)\n\n");
        scanf("%s",file_rar_name);                                      /*对应图片文件名字*/
        printf("\n请输入合成完毕的文件名:\n");
        scanf("%s",file_new_name);

        /*“wb”只写打开或新建一个二进制文件；只允许写数据。*/
        /*“rb” 只读打开一个二进制文件，只允许读数据*/

        fp_picture = NULL;
        fp_rar = NULL;
        fp_new = NULL;


        fp_rar = fopen(file_rar_name,"ab+");
        fp_picture = fopen(file_picture_name,"ab+");
        fp_new = fopen(file_new_name,"ab+");

        if(fp_rar == NULL || fp_picture == NULL || fp_new == NULL)
        {
            printf("错误!打开文件失败!\n");
            printf("请检查文件名是否正确\n");
            exit(1);
        }

        while(feof(fp_rar) == 0)
        {
            ch = fgetc(fp_rar);
            fputc(ch,fp_new);
        }

        fclose(fp_rar);
        fp_rar = NULL;
        fclose(fp_new);

        fp_new = fopen(file_new_name,"ab+");

        while(feof(fp_picture) == 0)
        {
            ch = fgetc(fp_picture);
            fputc(ch,fp_new);
        }


        fclose(fp_picture);
        fp_picture = NULL;

        fclose(fp_new);
        fp_new = NULL;

        printf("是否继续?\n(x/y):");
        ch = getch();
        if(ch == 'x')
        {
            printf("您选择了继续\n");
        }
        else if(ch == 'y')
        {
        	printf("\n");
            break;
        }
    }
    system("pause");
    return 0;
}
