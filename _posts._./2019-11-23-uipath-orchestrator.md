---
title: uipath ノート（三）- uipath orchestrator
date: 2019-11-23
tags:
    - RPA
    - uipath
---

## 利用手順

Official doc: [https://docs.uipath.com/robot/docs/from-orchestrator-and-the-orchestrator-settings-window](https://docs.uipath.com/robot/docs/from-orchestrator-and-the-orchestrator-settings-window)

### マシンを追加

マシン側でマシン名とユーザ名を確認

```
C:\Users\user>hostname
DESKTOP-ABCDE5F

C:\Users\user>whoami
desktop-abcde5f\user

C:\Users\user>
```

追加完了後、マシンキーを取得する。

### ロボットを登録

* Type: studio （開発用？）
* Domain/Username: 上記のユーザ名

### ローカルの orchestrator 設定

Uipath Robot を開き⇒orchestrator の設定で、上記のマシンキーを入力する。
orchestrator URL に `https://platform.uipath.com/` を入力する。
`Invalid machine key`というエラーが出たら、下記のような URL を試す：
```
https://platform.uipath.com/<account name>/<service name>
```

参照：[Uipath orchestrator error : invalid machine key](https://forum.uipath.com/t/uipath-orchestrator-error-invalid-machine-key/153438/16)

### ロボットグループ(Environment)作成

### プロジェクトをパブリッシュ(Publish)

### プロセスを追加

Automations　⇒　Processes

### ジョブ(Jobs)の実行

Monitoring　⇒　Jobs

## その他

### 再パブリッシュすると、Process が最新バージョンを使うため、変更作業が必要

Processes　⇒　More Options　⇒　View Process　⇒　最新のバージョンに切り替える

### ジョブの停止

* 停止(Stop)：必ずワークフロー内で「停止すべきか確認(Should Stop)」アクティビティを使用する
* 強制終了(Kill)：処理中の内容に関わらず、ジョブを停止する

### アクティブなジョブは削除できない

### パラメーター変更の優先順位

ジョブ (Jobs) -> プロセス (Processes) -> パッケージ(UiPath Studio)

### マシンテンプレート

Machine Templates only work for Active Directory users, Attended Floating Robots and Studio Floating Robots.
