# アルファベットを点字に変換するデバイスドライバ
ユーザーがアルファベット入力を行いLEDの出力によって点字を表現する。

---

改造内容


---

### 実行環境
Ubuntu 18.04

raspberry pi 4 Model B

---

### 実行方法
https://github.com/Tomoyayoshida/leddev.git をクローン

クローンしたディレクトリ内でmake

sudo insmod でカーネルモジュールをロード

sudo chmod 666 /dev/myled0　を入力し書き込み可能にする

---
# 動画
https://youtu.be/mm7KjFGx8Ms
# 作成者
Ryuichi Ueda and
Tomoya yoshida
# license
GPL-3.0 License
