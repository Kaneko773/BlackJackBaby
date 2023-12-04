// BlackJackBaby.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "Shoe.h"

#include "Player.h"
#include "Dealer.h"

using namespace std;

static void showResult(Player& player, Dealer& dealer)
{
    cout << "============================" << endl;
    cout << "            result          " << endl;
    cout << "============================" << endl;
    cout << "============================" << endl;
    cout << player.getName() << endl;
    player.showHand();
    cout << "============================" << endl;
    cout << dealer.getName() << endl;
    dealer.showHand();
    cout << "============================" << endl;

    if (player.calcScore() > dealer.calcScore()) {
        cout << "Player Win!" << endl;
    }
    else if (player.calcScore() < dealer.calcScore()) {
        cout << "Player Lose" << endl;
    }
    else {
        cout << "Push" << endl;
    }
}


static void showHand(Person& p)
{
    cout << "======================" << endl;
    cout << p.getName() << endl;
    p.showHand();
    cout << "======================" << endl;
}

int main()
{
    srand(time(NULL));

    Dealer d("suga D");
    Player p("hosaka");
    Shoe shoe;
    for (int i = 0; i < 2; i++)
    {
        p.hit(&shoe);
    }
    showHand(p);

    d.hit(&shoe);
    showHand(d);
    d.hit(&shoe);

    // まずはプレイヤーのターン処理
    if (p.play(&shoe) == true)
    {
        // プレイヤーがスタンドした場合の処理
        // 
        // 次はディーラーのターン処理
        d.play(&shoe);

        // 勝敗判定・結果表示をする
        showResult(p, d);
    }
    else
    {
        cout << "バーストしたのでおぬしの負けです。" << endl;
    }

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
