/*
 * @Author: your name
 * @Date: 2021-09-04 11:07:25
 * @LastEditTime: 2021-09-04 14:09:04
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Desktop\commodity_project\include\com_list.h
 */
#ifndef _COM_LIST_H
#define _COM_LIST_H

#include <list.h>

#define HISTORY_FILE_NAME   "shopping_history.txt"

//商品信息节点
typedef struct commodity_info_node{
    char com_name[40];//商品名字
    float com_price;//商品价格
    unsigned int com_stock;//商品库存

    struct list_head list;//内核链表小个结构体
}com_node_t;

//购物车信息节点
typedef struct shopping_car_node{
    
    com_node_t *com_node;//用来记录之后购物的商品信息的节点地址

    unsigned int shopping_numb;//购物数量

    struct list_head list;//内核链表小个结构体

}scar_node_t;

//公共资源管理结构体
struct resource_manage{
    //商品信息链表
    com_node_t *com_list;
    //购物车链表
    scar_node_t *scar_list;
    //历史文件信息
    char history_file[20];
};


#endif/*end of _COM_LIST_H*/