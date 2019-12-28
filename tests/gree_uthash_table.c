#include "../include/uthash.h"
#include <stdlib.h>   /* malloc */
#include <stdio.h>    /* printf */

#define POW     "Pow"
#define Sleep   "Sleep"
#define Spled   "Spled"
const char *keys[] = {
                POW,Sleep,Spled
        };

struct gree_ctrls {
        const char *name;
        int val;
        UT_hash_handle hh;
};
struct gree_ctrls *head = NULL; 

/*
* 创建字段并初始化
*/
struct gree_ctrls *create_item(const char *name, const int val)
{
        struct gree_ctrls * tmp = (struct gree_ctrls *)malloc(sizeof(struct gree_ctrls));
        tmp->name = name;
        tmp->val = val;
}
/*
* 创建的字段插入到hash表中
*/
void insert_item(struct gree_ctrls *tmp)
{
        HASH_ADD_KEYPTR(hh,head,tmp->name,strlen(tmp->name),tmp);
}
/*
* 修改hash表中的某个字段的数据
*/
void modified_item(const char *name, const int val)
{
        struct gree_ctrls *tmp = NULL;
        HASH_FIND(hh, head, name, strlen(name), tmp);
        tmp->val = val;
}
int main(int argc, char *argv[])
{
        int i;
        for(i=0; i < (sizeof(keys)/sizeof(keys[0])); i++) {
                printf("adding key %s\n", keys[i]);
                insert_item(create_item(keys[i],5));
        }
        modified_item(POW, 100);
        return 0;
}
