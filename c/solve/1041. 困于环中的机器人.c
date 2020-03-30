/* 
    在无限的平面上，机器人最初位于 (0, 0) 处，面朝北方。机器人可以接受下列三条指令之一：
        "G"：直走 1 个单位
        "L"：左转 90 度
        "R"：右转 90 度

    机器人按顺序执行指令 instructions，并一直重复它们。

    只有在平面中存在环使得机器人永远无法离开时，返回 true。否则，返回 false。
 */
bool isRobotBounded(char * instructions){
    int i,direction=0;
    //direction中，0代表上，1代表左，2代表下，3代表右
    int posX=0,posY=0;
    for(i=0;instructions[i]!='\0';i++){
        if(instructions[i]=='G'){
            if(direction%4==0) posY++;
            else if(direction%4==1) posX--;
            else if(direction%4==2) posY--;
            else if(direction%4==3) posX++;

        }
        else if(instructions[i]=='L'){
            direction++;
        }
        else if(instructions[i]=='R'){
            direction+=3;
        }

    }
    if(posX==0&&posY==0){
        return true;
    }
    if(direction%4!=0){
        return true;
    }
    return false;
}