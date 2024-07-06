#include <stdio.h>

/**
* admin���߱����ʲ�
* Time�� 2024/7/1 20:59
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
* ����������ӿͻ�
* ���ߣ�lemontea
* ���ڣ�
* ���ܣ�ʵ����ӿͻ�
* ��������
* ����ֵ��USER����
* �޸ļ�¼:
*/
USER  *add_user(){
    static USER u;
    printf("\n----------�� �� �� ��----------\n");
    printf("����:");
    scanf("%s",&u.name);
    printf("�Ա�:");
    scanf("%s",&u.sex);
    printf("����:");
    scanf("%d",&u.age);
    printf("�绰:");
    scanf("%d",&u.iphone_number);
    printf("����:");
    scanf("%s",&u.email);

    return &u;
}
/**
* ���������޸Ŀͻ�
* ���ߣ�lemontea
* ���ڣ�
* ���ܣ������������Ϣ�޸���Ϣ
* ������USER���͵�����
* ����ֵ��USER����
* �޸ļ�¼:
*/
USER *update_user(USER *u){
    static USER user;
    printf("\n----------�� �� �� ��----------\n");
    printf("����(%s):",&u->name);
    scanf("%s",&user.name);
    printf("�Ա�(%s):",u->sex);
    scanf("%s",&user.sex);
    printf("����(%d):",u->age);
    scanf("%d",&user.age);
    printf("�绰(%d):",u->iphone_number);
    scanf("%d",&user.iphone_number);
    printf("����(%s):",u->email);
    scanf("%s",&user.email);
    return &user;
}

void delete_user(USER *u,int id,int *len){
    char is_delete;
    printf("ȷ���Ƿ�ɾ��(Y/N)\n");
    getchar();
    scanf("%c",&is_delete);
    if(is_delete=='Y'||is_delete=='y'){
            for(int j = id;j < *len;j++){
                u[j]=u[j+1];
        }
    } else if(is_delete=='N'||is_delete=='n'){
        printf("\n----------ȡ �� ɾ ��----------\n");
    } else{
        printf("�����������������\n");
    }

}
void print_user(USER *u , int len){
    if(len<=0){
        printf("��û�������������������ݣ���\n");
    }else{
        for (int i = 0; i < len; i++) {
            printf("\n���      ����      �Ա�      ����      �绰      ����\n");
            printf("%d        %s       %s       %d        %d        %s\n",i+1,u[i].name,u[i].sex,u[i].age,u[i].iphone_number,u[i].email);
        }
    }

}
int *show_user(){
    static int id;
    printf("\n----------�ͻ���Ϣ�������----------\n");
    printf("          1 �� �� �� ��\n");
    printf("          2 �� �� �� ��\n");
    printf("          3 ɾ �� �� ��\n");
    printf("          4 �� �� �� ��\n");
    printf("          5 ��      ��\n");
    printf("          ��ѡ��(1-5)\n");
    scanf("%d",&id);

    return &id;
}

int main() {
    //������Ҫ�޸ĵ������±�
    int update_index,user_id=0;
    int delete_id;
    USER user[100];
    while (1){
        //չʾ��ҳ��
        int *id = show_user();
        if(*id>5||*id<=0){
            printf("�����������������\n");printf("\n");
        }
        //�����û�����ѡ��
        switch (*id) {
            //����û�
            case 1:{
                USER *u = add_user() ;
                user[user_id] = *u;
                user_id++;
                print_user(&user,user_id);
                break;
            }
            //�޸Ŀͷ���Ϣ
            case 2:{
                if(user_id>0){
                    printf("\n----------�� �� �� ��----------\n");
                    printf("������Ҫ�޸ĵ��û����:");
                    scanf("%d",&update_index);
                    user[update_index-1] = *update_user(&user[update_index-1]);
                    print_user(&user,user_id);
                } else{
                    printf("û�д���ͻ�����������û�\n");
                    printf("\n");
                }
                break;
            }
            //ɾ���ͻ���Ϣ
            case 3:{
                if(user_id>0){
                printf("\n----------ɾ �� �� ��----------\n");
                printf("������ɾ���ͻ��ı��:");
                scanf("%d",&delete_id);
                delete_user(&user,delete_id-1,&user_id);
                user_id--;
                if(user_id>0){
                    print_user(&user,user_id);
                } else{
                    printf("��ɾ�����пͻ���������û�\n");
                }
                } else{
                printf("û�д���ͻ�����������û�\n");
                printf("\n");
            }
                break;
            }
            //չʾ�û���Ϣ
            case 4:{
                if(user_id>0){
                print_user(&user,user_id);
                } else{
                    printf("û�д���ͻ�����������û�\n");
                    printf("\n");
                }
                break;

            }
            //�˳�����
            case 5:
                goto END;
        }

    }




    END:
    printf("�������");
    return 0;
}