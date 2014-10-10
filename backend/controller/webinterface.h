/*
* Copyright (C) 2007-2013 Alibaba Group Holding Limited
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*/

#ifndef WEBINTERFACE_H
#define WEBINTERFACE_H
#include <string>
#include <map>
struct AgentSystemInfo;
class WebInterfaces
{
public:
   static int SetAllAgentToDown();
    static int SetAllRunToComplete();
    // return timer task number
    //  {"1":"0 0 * * *","22":"0 1 * * *"}
    static int GetTimerTaskList();
 
    // name ������
    // status ����״̬��0 idle; 1 running; 2 down
    // version Agent�汾��
    // type OS���ͣ�0 linux; 1 windows
    // desc_info ������Ϣ������Ӳ����Ϣ��OS��Ϣ�� 
    
    static void UpdateMachineStatus(const std::string &name, int status);

    static void UpdateMachineInfoStatusIdle(const AgentSystemInfo& info, const std::string &other_info);
    
    //id ��������ID
    // status ����״̬��0 waitting; 1 running; 2 complete; 3 canceled; 4 timeout; 5 abort; 10 canceling
    // return_value�����ֵ
    // desc_info ������Ϣ
    static int UpdateTaskInfo(int run_id, int status, int return_value, const std::string &info);
    static void StartTimerTask(int task_id);
   
private:
    // function write_calback, this is called by libcurl get data form server
    // CURLOPT_WRITEFUNCTION  CURLOPT_WRITEDATA
    static size_t CurlWriteCallback( char *ptr, size_t size, size_t nmemb, void *server_return);
  
    static int CurlPost(const std::string& url, const std::string& post_msg, std::string *returnString);
 };

#endif

