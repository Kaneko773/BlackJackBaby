// BlackJackBaby.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "Shoe.h"

#include "Player.h"
#include "Dealer.h"

using namespace std;

static void showAll(Player(&player)[4], Dealer& dealer);

static void showResult(Player(&p)[4], Dealer& d)
{
    cout << "============================" << endl;
    cout << "            result          " << endl;
    cout << "============================" << endl;
    showAll(p, d);
    for (int i = 0; i < 4; ++i) {
        if (p[i].calcScore() > d.calcScore()) {
            printf("%-29s", "Win!");
        }
        else if (p[i].calcScore() < d.calcScore()) {
            printf("%-29s", "Lose");
        }
        else {
            printf("%-29s", "Push");
        }
    }
}


static void showHand(Person& person)
{
    cout << "======================" << endl;
    cout << person.getName() << endl;
    person.showHand();
    cout << "======================" << endl;
}

static void showAll(Player(&player)[4], Dealer& dealer)
{
    cout << "======================" << endl;
    cout << "Dealer" << endl;
    cout << dealer.getName() << endl;
    dealer.showHand();
    cout << "======================" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "============================ " << flush;
    }cout << endl;
    cout << "Players" << endl;
    for (int i = 0; i < 4; ++i) {
        printf("%-29s", player[i].getName());
    }cout << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (j < player[i].get_cardNum()) {
                player[i].showOneCard(j);
            }
            else {
                cout << "    " << flush;
            }
        }
        cout << " ";
    }
    cout << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 7; j < 14; ++j) {
            if (j < player[i].get_cardNum()) {
                player[i].showOneCard(j);
            }
            else {
                cout << "    " << flush;
            }
        }
        cout << " ";
    }
    cout << endl;
    for (int i = 0; i < 4; ++i) {
        printf("score:%-23d", player[i].calcScore());
    }
    cout << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "============================ " << flush;
    }cout << endl;
}

int main()
{
    srand(time(NULL));

    Dealer d("suga D");
    Player p[4] = { "hosaka", "tokita", "nagasaka", "kaenko" };
    Shoe shoe;
    int burstNum = 0;

    d.hit(&shoe);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; j++)
        {
            p[i].hit(&shoe);
        }
    }
    showAll(p, d);
    d.hit(&shoe);

    for (int i = 0; i < 4; ++i) {
        showHand(p[i]);
        if (!p[i].play(&shoe)) ++burstNum;
    }
    if(burstNum < 4)d.play(&shoe);
    showResult(p, d);
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
