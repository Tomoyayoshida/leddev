# アルファベットを点字に変換するデバイスドライバ
ユーザーがアルファベット入力を行いLEDの出力によって点字を表現する。

robosys2020 task1

---

# 改造内容
講義中に作成したデバイスドライバがより多くのLEDを処理できるように改造を行った。

---

# 実行環境
Ubuntu 20.04

raspberry pi 4 Model B

---

# 部品
・3mmLED×6（2.0V~2.2V）

・220Ωの抵抗×6

・raspberry　pi 4 Model B

・ジャンプワイヤ×7

# 回路図

![image](https://user-images.githubusercontent.com/73051935/101175120-1fafd000-3688-11eb-86fe-5111b72d97a8.png)

### 実行方法
https://github.com/Tomoyayoshida/leddev.git をクローン

クローンしたディレクトリ内でmake

sudo insmod でカーネルモジュールをロード

sudo chmod 666 /dev/myled0　を入力し書き込み可能にする

echo a > /dev/myled0 アルファベットの入力によりアルファベットの点字の突起部と同じ個所のLEDが点灯する。

echo 1 > /dev/myled0 １を出力するとLEDが全点灯、０ですべて消える。

---


# 動画
https://youtu.be/mm7KjFGx8Ms
# 作成者
Tomoya yoshida and Ryuichi Ueda 
# license
GPL-3.0 License
