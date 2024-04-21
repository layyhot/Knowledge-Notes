1. git log：查看提交历史记录
2. git rebase -i HEAD~N ：N是你想要保留的提交记录数量，替换为你要编辑的提交记录的数量。如果你想删除最近的一次提交记录，则 N 应该是 1
找到你想要删除的提交记录所对应的行，然后将其前面的单词改为 drop，表示你想要删除它。
3. 如果删除提交后需要将更改推送到远程仓库，请使用强制推送（--force）：
git push origin <branch-name> --force

1. 重定向到新的远程仓库 URL 并不会影响你本地仓库的配置或内容。你只需更新本地仓库的远程仓库 URL 即可。
你可以使用以下命令来更新远程仓库 URL：
git remote set-url origin git@github.com:layyhot/GD32F470ZGT6-.git（新的SSH地址）
2. 想要克隆名为 "example_repo" 的仓库，可以这样做：
git clone git@github.com:layyhot/GD32F470ZGT6-.git

1. git init：创建一个仓库
2. git status: 查看仓库文件状态
3. git add .:将所以变动的文件加入暂存区
4. git commit -m "**提交备注**" 或
git commit 先按i进入编辑备注，在Esc退出编辑，最后输入：wq（保存并退出）
