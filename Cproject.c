#include <stdio.h>

/**
* admin：七杯柠檬茶
* Time： 2024/7/1 20:59
*
*/

typedef struct user{
    char name[15];
    char sex[4];
    int age;
    int iphone_number;
    char email[20];
} USER;
/**
* 函数名：添加客户
* 作者：lemontea
* 日期：
* 功能：实现添加客户
* 参数：无
* 返回值：USER类型
* 修改记录:
*/
USER  *add_user(){
    static USER u;
    printf("\n----------添 加 客 户----------\n");
    printf("姓名:");
    scanf("%s",&u.name);
    printf("性别:");
    scanf("%s",&u.sex);
    printf("年龄:");
    scanf("%d",&u.age);
    printf("电话:");
    scanf("%d",&u.iphone_number);
    printf("邮箱:");
    scanf("%s",&u.email);

    return &u;
}
/**
* 函数名：修改客户
* 作者：lemontea
* 日期：
* 功能：输出传来的信息修改信息
* 参数：USER类型的数据
* 返回值：USER类型
* 修改记录:
*/
USER *update_user(USER *u){
    static USER user;
    printf("\n----------修 改 客 户----------\n");
    printf("姓名(%s):",&u->name);
    scanf("%s",&user.name);
    printf("性别(%s):",u->sex);
    scanf("%s",&user.sex);
    printf("年龄(%d):",u->age);
    scanf("%d",&user.age);
    printf("电话(%d):",u->iphone_number);
    scanf("%d",&user.iphone_number);
    printf("邮箱(%s):",u->email);
    scanf("%s",&user.email);
    return &user;
}

void delete_user(USER *u,int id,int *len){
    char is_delete;
    printf("确认是否删除(Y/N)\n");
    getchar();
    scanf("%c",&is_delete);
    if(is_delete=='Y'||is_delete=='y'){
            for(int j = id;j < *len;j++){
                u[j]=u[j+1];
        }
    } else if(is_delete=='N'||is_delete=='n'){
        printf("\n----------取 消 删 除----------\n");
    } else{
        printf("输入错误请重新输入\n");
    }

}
void print_user(USER *u , int len){
    if(len<=0){
        printf("还没有数据请您先输入数据！！\n");
    }else{
        for (int i = 0; i < len; i++) {
            printf("\n编号      姓名      性别      年龄      电话      邮箱\n");
            printf("%d        %s       %s       %d        %d        %s\n",i+1,u[i].name,u[i].sex,u[i].age,u[i].iphone_number,u[i].email);
        }
    }

}
int *show_user(){
    static int id;
    printf("\n----------客户信息管理软件----------\n");
    printf("          1 添 加 客 户\n");
    printf("          2 修 改 客 户\n");
    printf("          3 删 除 客 户\n");
    printf("          4 客 户 列 表\n");
    printf("          5 退      出\n");
    printf("          请选择(1-5)\n");
    scanf("%d",&id);

    return &id;
}

int main() {
    //定义需要修改的数据下标
    int update_index,user_id=0;
    int delete_id;
    USER user[100];
    while (1){
        //展示主页面
        int *id = show_user();
        if(*id>5||*id<=0){
            printf("输入错误请重新输入\n");printf("\n");
        }
        //根据用户输入选择
        switch (*id) {
            //添加用户
            case 1:{
                USER *u = add_user() ;
                user[user_id] = *u;
                user_id++;
                print_user(&user,user_id);
                break;
            }
            //修改客服信息
            case 2:{
                if(user_id>0){
                    printf("\n----------修 改 客 户----------\n");
                    printf("请输入要修改的用户编号:");
                    scanf("%d",&update_index);
                    user[update_index-1] = *update_user(&user[update_index-1]);
                    print_user(&user,user_id);
                } else{
                    printf("没有储存客户请您先添加用户\n");
                    printf("\n");
                }
                break;
            }
            //删除客户信息
            case 3:{
                if(user_id>0){
                printf("\n----------删 除 客 户----------\n");
                printf("请输入删除客户的编号:");
                scanf("%d",&delete_id);
                delete_user(&user,delete_id-1,&user_id);
                user_id--;
                if(user_id>0){
                    print_user(&user,user_id);
                } else{
                    printf("已删除所有客户请先添加用户\n");
                }
                } else{
                printf("没有储存客户请您先添加用户\n");
                printf("\n");
            }
                break;
            }
            //展示用户信息
            case 4:{
                if(user_id>0){
                print_user(&user,user_id);
                } else{
                    printf("没有储存客户请您先添加用户\n");
                    printf("\n");
                }
                break;

            }
            //退出程序
            case 5:
                goto END;
        }

    }




    END:
    printf("程序结束");
    return 0;
}