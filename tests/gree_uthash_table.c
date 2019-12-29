#include "../include/uthash.h"
#include <stdlib.h>   /* malloc */
#include <stdio.h>    /* printf */

#define         cJSON_Pow              	    "Pow"
#define         cJSON_Mod              	    "Mod"
#define	        cJSON_SwhSlp                "SwhSlp"
#define	        cJSON_SwhSw                 "SwhSw"
#define	        cJSON_WdSpd                 "WdSpd"
#define	        cJSON_SetTem                "SetTem"
#define	        cJSON_Blo                   "Blo"
#define	        cJSON_Health                "Health"
#define	        cJSON_Lig                   "Lig"
#define	        cJSON_TemUn                 "TemUn"
#define	        cJSON_TemRec                "TemRec"
#define	        cJSON_Air                   "Air"
#define	        cJSON_SwUpDn                "SwUpDn"
#define	        cJSON_SwingLfRig            "SwingLfRig"
#define	        cJSON_SvSt                  "SvSt"
#define	        cJSON_StHt8                 "StHt8"
#define	        cJSON_Intellblo1            "Intellblo1"
#define         cJSON_Savpow                "Savpow"
#define         cJSON_AirOpen               "AirOpen"
#define	        cJSON_Voltnum               "Voltnum"
#define         cJSON_Currnum               "Currnum"
#define         cJSON_Powernum              "Powernum"
#define         cJSON_hid                   "hid"
#define         cJSON_time                  "time"
#define         cJSON_Electnumzero          "Electnumzero"
#define         cJSON_Studied              "Studied"
#define         cJSON_DelButton            "DelButton"
#define         cJSON_AddButton            "AddButton"
#define         cJSON_SendButton           "SendButton"
#define         cJSON_SlpMod               "SlpMod"
#define         cJSON_Tur                  "Tur"                
#define         cJSON_Quiet                "Quiet"              
#define         cJSON_VoltErr              "VoltErr"
#define         cJSON_CurrErr              "CurrErr"
#define         cJSON_PowerErr             "PowerErr"
#define         cJSON_ACCntlrShape         "ACCntlrShape"
#define         cJSON_RelayErr             "RelayErr"
#define         cJSON_AppSetTimer          "AppTimer"
#define         cJSON_RefBtnList           "RefBtnList"
#define         cJSON_ConBtnNum            "ConBtnNum"
#define         cJSON_ConBtnName           "ConBtnName"
#define         cJSON_ProTimeLen           "ProTimeLen"
#define         cJSON_ProTimePow           "ProTimePow"
#define         cJSON_ProTimeReminder      "ProTimeReminder"
#define         cJSON_RealTimePower        "RealTimePower"
#define         cJSON_MidType              "MidType"
#define         cJSON_VoiceGate            "VoiceGate"
#define         cJSON_VoiceVolume          "VoiceVolume"

struct gree_ctrls {
        const char *key;
        int val;
        UT_hash_handle hh;
};
struct gree_ctrls *head = NULL; 
/*
* 创建字段并初始化
*/
struct gree_ctrls *uthash_create(const char *key, const int val)
{
        struct gree_ctrls *tmp = (struct gree_ctrls *)malloc(sizeof(struct gree_ctrls));
        tmp->key = key;
        tmp->val = val;
}
/*
* 创建的字段插入到hash表中
*/
void uthash_insert(struct gree_ctrls *tmp)
{
        HASH_ADD_KEYPTR(hh,head,tmp->key,strlen(tmp->key),tmp);
}
/*
* 修改hash表中的某个字段的数据
*/
void uthash_modified_item(const char *key, const int val)
{
        struct gree_ctrls *tmp = NULL;
        HASH_FIND(hh, head, key, strlen(key), tmp);
        tmp->val = val;
}
/*
* 查找某个字段的数据
*/
int uthash_get(const char *key)
{
        struct gree_ctrls *tmp = NULL;
        int i = 0;
        HASH_FIND(hh, head, key, strlen(key), tmp);
        i = tmp->val;
        return i;
}
// unsigned short int ARRBUF[ARRBUF_SUM]={0,0,0,0,0,0,0,0,300,18,5000,0,0,0,0,0,0};
/*
* 字段初始化
*/
void gree_words_init(void)
{
        uthash_insert(uthash_create(cJSON_Pow,                  0));
        uthash_insert(uthash_create(cJSON_Mod,                  1));
        uthash_insert(uthash_create(cJSON_SwhSlp,               0));
        uthash_insert(uthash_create(cJSON_SwhSw,                0));
        uthash_insert(uthash_create(cJSON_WdSpd,                1));
        uthash_insert(uthash_create(cJSON_SetTem,               16));
        uthash_insert(uthash_create(cJSON_Blo,                  0));
        uthash_insert(uthash_create(cJSON_Health,               0));
        uthash_insert(uthash_create(cJSON_Lig,                  1));
        uthash_insert(uthash_create(cJSON_TemUn,                0));
        uthash_insert(uthash_create(cJSON_TemRec,               0));
        uthash_insert(uthash_create(cJSON_Air,                  0));
        uthash_insert(uthash_create(cJSON_SwUpDn,               0));
        uthash_insert(uthash_create(cJSON_SwingLfRig,           0));
        uthash_insert(uthash_create(cJSON_SvSt,                 0));
        uthash_insert(uthash_create(cJSON_StHt8,                0));
        uthash_insert(uthash_create(cJSON_Intellblo1,           0));
        uthash_insert(uthash_create(cJSON_Savpow,               0));
        uthash_insert(uthash_create(cJSON_AirOpen,              0));
        uthash_insert(uthash_create(cJSON_Voltnum,              0));
        uthash_insert(uthash_create(cJSON_Currnum,              0));
        uthash_insert(uthash_create(cJSON_Powernum,             0));
        uthash_insert(uthash_create(cJSON_hid,                  0));
        uthash_insert(uthash_create(cJSON_time,                 0));
        uthash_insert(uthash_create(cJSON_Electnumzero,         0));
        uthash_insert(uthash_create(cJSON_Studied,              0));
        uthash_insert(uthash_create(cJSON_DelButton,            0));
        uthash_insert(uthash_create(cJSON_AddButton,            0));
        uthash_insert(uthash_create(cJSON_SendButton,           0));
        uthash_insert(uthash_create(cJSON_SlpMod,               0));
        uthash_insert(uthash_create(cJSON_Tur,                  0));
        uthash_insert(uthash_create(cJSON_Quiet,                0));
        uthash_insert(uthash_create(cJSON_VoltErr,              0));
        uthash_insert(uthash_create(cJSON_CurrErr,              0));
        uthash_insert(uthash_create(cJSON_PowerErr,             0));
        uthash_insert(uthash_create(cJSON_ACCntlrShape,         0));
        uthash_insert(uthash_create(cJSON_RelayErr,             0));
        uthash_insert(uthash_create(cJSON_AppSetTimer,          0));
        uthash_insert(uthash_create(cJSON_RefBtnList,           0));
        uthash_insert(uthash_create(cJSON_ConBtnNum,            0));
        uthash_insert(uthash_create(cJSON_ConBtnName,           0));
        uthash_insert(uthash_create(cJSON_ProTimeLen,           0));
        uthash_insert(uthash_create(cJSON_ProTimePow,           0));
        uthash_insert(uthash_create(cJSON_ProTimeReminder,      0));
        uthash_insert(uthash_create(cJSON_RealTimePower,        0));
        uthash_insert(uthash_create(cJSON_MidType,              0));
        uthash_insert(uthash_create(cJSON_VoiceGate,            0));
        uthash_insert(uthash_create(cJSON_VoiceVolume,          0));
}
int main(int argc, char *argv[])
{
        gree_words_init();
        return 0;
}
