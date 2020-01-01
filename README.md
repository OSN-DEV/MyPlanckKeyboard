# Summary
Windows + JIS配列での使用を前提としたキー配列の画像、HEX、JSONを上げています。
キーマッピングは QMK Configurator で作成しているためか、マウスキーは動作していません。

## 2019.12.31
かなり久々にいじろうとしたとことすっかり手順を忘れていたので備忘録を追記

### キーマッピングの設定
* [QMK](https://config.qmk.fm/)にアクセス
* 保存済みのJSONを読込(JSONのキーボード名が合致していないとレイアウトが何も表示されない)
* キーマッピングが完了したら[COMPILE]を実行
* 成功したら[FIRMWARE]を押下してファームをダウンロード


### ドライバのインストール
[Flip](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/FLIP)をインストールしてUSBドライバをインスール(ツールをインストールしただけではドライバが適用されていないかも。自分はデバイスドライバから手動でドライバをインストールしました)


### ファーム焼き
[qmk_toolbox](https://github.com/qmk/qmk_toolbox/releases)を使ってファームをインストール。Hex以外はすべてデフォルト。
※ドライバをインストールしていないと何をしてもファーム焼きに失敗する 