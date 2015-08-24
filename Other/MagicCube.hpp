#include <iostream>
#include <map>
using namespace std;


/**
 * 魔方按照前面的方式展开
 *   0
 * 4 2 5
 *   1
 *   3
 *
 * 每个面的数字编码顺序为
 *  0 1 2
 *  3 4 5
 *  6 7 8
 *
 *
 * 阿里2016年算法工程师笔试题
 *
 */

class MagicCube
{
private:
    enum{LEN = 3,SPACE = 6};
    enum color{W, Y, R, O, G, B};
    enum color Spacexy[SPACE][LEN][LEN];
    map<int, string> int2col;
public:
    MagicCube();
    ~MagicCube(){};
    void LeftRotate();
    void RightRotate();
    void FrontRotate();
    void BackRotate();
    void UpRotate();
    void DownRotate();
    void Rotate(int s);
    void PrintCube();
};

MagicCube::MagicCube()
{
    for(int i = 0;i<6;i++)//每一面一个颜色
        for(int j = 0;j<3;j++)
            for(int k = 0;k<3;k++)
            {
                Spacexy[i][j][k] = (color)i;
            }

    int2col[0] = "W";
    int2col[1] = "Y";
    int2col[2] = "R";
    int2col[3] = "O";
    int2col[4] = "G";
    int2col[5] = "B";

}

void MagicCube::FrontRotate()
{
    Rotate(2);

    color tmp[3];

    for(int i = 0;i<3;i++)
        tmp[i] = Spacexy[0][2][i];

    for(int i = 0; i<3;i++)
        Spacexy[0][2][i] = Spacexy[4][2-i][2];
    for(int i = 0;i<3;i++)
        Spacexy[4][i][2] = Spacexy[1][0][i];
    for(int i = 0;i<3;i++)
        Spacexy[1][0][i] = Spacexy[5][2-i][0];
    for(int i = 0;i<3;i++)
        Spacexy[5][i][0] = tmp[i];
}

void MagicCube::BackRotate()
{
    Rotate(3);

    color tmp[3];

    for(int i = 0;i<3;i++)
        tmp[i] = Spacexy[1][2][i];

    for(int i = 0; i<3;i++)
        Spacexy[1][2][i] = Spacexy[4][i][0];
    for(int i = 0;i<3;i++)
        Spacexy[4][i][0] = Spacexy[0][0][2-i];
    for(int i = 0;i<3;i++)
        Spacexy[0][0][i] = Spacexy[5][i][2];
    for(int i = 0;i<3;i++)
        Spacexy[5][i][2] = tmp[2-i];
}

void MagicCube::RightRotate()
{
    Rotate(5);

    color tmp[3];

    for(int i = 0;i<3;i++)
        tmp[i] = Spacexy[3][i][2];

    for(int i = 0; i<3;i++)
        Spacexy[3][i][2] = Spacexy[0][i][2];
    for(int i = 0;i<3;i++)
        Spacexy[0][i][2] = Spacexy[2][i][2];
    for(int i = 0;i<3;i++)
        Spacexy[2][i][2] = Spacexy[1][i][2];
    for(int i = 0;i<3;i++)
        Spacexy[1][i][2] = tmp[i];
}

void MagicCube::DownRotate()
{
    Rotate(1);

    color tmp[3];

    for(int i = 0;i<3;i++)
        tmp[i] = Spacexy[3][0][i];

    for(int i = 0; i<3;i++)
        Spacexy[3][0][i] = Spacexy[5][2][2-i];
    for(int i = 0;i<3;i++)
        Spacexy[5][2][i] = Spacexy[2][2][i];
    for(int i = 0;i<3;i++)
        Spacexy[2][2][i] = Spacexy[4][2][i];
    for(int i = 0;i<3;i++)
        Spacexy[4][2][i] = tmp[2-i];

}

void MagicCube::Rotate(int s)
{
    color tmp[3];
    for(int i=0; i<3; i++)
        tmp[i] = Spacexy[s][0][i];

    for(int i=0; i<3; i++)
        Spacexy[s][0][i] = Spacexy[s][2-i][0];
    for(int i=0; i<3; i++)
        Spacexy[s][i][0] = Spacexy[s][2][i];
    for(int i=0; i<3; i++)
        Spacexy[s][2][i] = Spacexy[s][2-i][2];
    for(int i=0; i<3; i++)
        Spacexy[s][2-i][2] = tmp[i];
}

void MagicCube::UpRotate()
{
    Rotate(0);

    color tmp[3];

    for(int i = 0;i<3;i++)
        tmp[i] = Spacexy[3][2][i];

    for(int i = 0; i<3;i++)
        Spacexy[3][2][i] = Spacexy[4][0][2-i];
    for(int i = 0;i<3;i++)
        Spacexy[4][0][i] = Spacexy[2][0][i];
    for(int i = 0;i<3;i++)
        Spacexy[2][0][i] = Spacexy[5][0][i];
    for(int i = 0;i<3;i++)
        Spacexy[5][0][i] = tmp[2-i];
}


void MagicCube::PrintCube()
{
    for(int s = 0; s<6;s++)
    {
        cout<< int2col[Spacexy[s][1][1]];
        int i = 2;
        int j = 0;
        for(int i=2; i>=0; i--)
            cout<<int2col[Spacexy[s][i][j]];
        i=0;
        for(int j=1; j<=2; j++)
            cout<<int2col[Spacexy[s][i][j]];
        cout<<int2col[Spacexy[s][1][2]]<<int2col[Spacexy[s][2][2]]<<int2col[Spacexy[s][2][1]]<<endl;

    }

}


void MagicCube::LeftRotate()
{
    Rotate(4);

    color tmp[3];

    for(int i = 0;i<3;i++)
        tmp[i] = Spacexy[3][i][0];

    for(int i = 0;i<3;i++)
        Spacexy[3][i][0] = Spacexy[1][i][0];
    for(int i = 0;i<3;i++)
        Spacexy[1][i][0] = Spacexy[2][2-i][0];
    for(int i = 0;i<3;i++)
        Spacexy[2][i][0] = Spacexy[0][i][0];
    for(int i = 0;i<3;i++)
        Spacexy[0][i][0] = tmp[2-i];

}


int magicCubeRun() {
    while(1) {
        string action;
        cin >> action;
        if(action == "q")
            break;
        MagicCube magic;
        for (int i = 0; i < action.size(); i++) {
            switch (action[i]) {
                case 'U':
                    magic.UpRotate();
                    break;
                case 'D':
                    magic.DownRotate();
                    break;
                case 'F':
                    magic.FrontRotate();
                    break;
                case 'B':
                    magic.BackRotate();
                    break;
                case 'L':
                    magic.LeftRotate();
                    break;
                case 'R':
                    magic.RightRotate();
                    break;
            }
        }
        magic.PrintCube();
    }
    return 0;
}