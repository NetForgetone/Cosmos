/***************************************
* 函 数 名：  _strwrite
* 功能描述： printf 函数直接调用了 _strwrite 函数，
             而 _strwrite 函数正是将字符串里每个字符依次定入到 0xb8000 地址开始的显存中，
            而 p_strdst 每次加 2，这也是为了跳过字符的颜色信息的空间。
* 输   入：char * string
* 输   出：NULL
* 返回值： NULL
* 修 改 者：    lxw       日期：2021.08.31
****************************************/
 void _strwrite(char *string)
{
    char* p_strdst = (char *)(0xb8000);  //指向显存的起始地址
    while(*string)
    {
        *p_strdst = *string++;   //赋值
         p_strdst += 2;
    }
    return;
}

/***************************************
* 函 数 名： printf 
* 功能描述： 外部调用api，打印字符接口函数
* 输   入：fmt: char 型地址指针， 其他
* 输   出：NULL
* 返回值： NULL
* 修 改 者： lxw          日期：2021.08.31
****************************************/
void printf(char * fmt,...)
{
    _strwrite(fmt);
    return;
}
