# アルファベットを点字に変換するデバイスドライバ
## リポジトリ概要　
**ユーザーがアルファベット入力を行いLEDの出力によって点字を表現するプログラム**

robosys2020 task1

## 改造内容
- 講義中に作成したデバイスドライバがより多くのLEDを処理できるようmyled.c内の改造を行った。
## 動作環境
- Ubuntu 20.04
- Raspberry Pi 4 Model B
## 用いた部品
- ブレッドボード
- 3mmLED×6（2.0V~2.2V）
- 220Ωの抵抗×6
- Raspberry　Pi 4 Model B
- ジャンプワイヤ×7
 
## 回路図

![image](https://user-images.githubusercontent.com/73051935/101175120-1fafd000-3688-11eb-86fe-5111b72d97a8.png)

## インストール方法
`$ git clone https://github.com/Tomoyayoshida/leddev.git` しリポジトリをクローン

クローンしたリポジトリ内で`$ make`

`$sudo insmod myled.ko`でカーネルモジュールをロード

`$sudo chmod 666 /dev/myled0`　を入力し書き込み可能にする

## 使用方法
`$ echo a > /dev/myled0` アルファベットの入力によりアルファベットの点字の突起部と同じ個所のLEDが点灯する。

`$ echo 1 > /dev/myled0` １を出力するとLEDが全点灯、０ですべて消える。
## 終了方法
`$ sudo rmmod myled` でカーネルモジュールの取り外し

`$ make clean` で元のファイルの状態へ戻す
## 動画
https://youtu.be/mm7KjFGx8Ms
## 作成者
Tomoya yoshida and Ryuichi Ueda 
## license
GPL-3.0 License
