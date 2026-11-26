# 贡献指南 (Contributing Guide)

感谢你考虑为 **{{PROJECT_NAME}}** 做贡献！🎉

## 行为准则

参与本项目即表示你同意遵守我们的 [行为准则](CODE_OF_CONDUCT.md)。

## 提交流程

1. **Fork** 本仓库并克隆到本地。
2. 从 `main`（或 `master`）切出特性分支：
   ```bash
   git checkout -b feat/你的功能名
   # 或 fix/问题名
   ```
3. 提交改动，遵循下方**提交信息规范**。
4. 推送分支并发起 Pull Request，使用 PR 模板填写必要信息。
5. 等待 CI 通过与至少一名维护者 Review。

## 提交信息规范 (Conventional Commits)

```
<type>(<scope>): <subject>

<body>  # 可选
```

常用 `type`：

| type     | 含义                       |
| -------- | -------------------------- |
| feat     | 新功能                     |
| fix      | 修复 bug                   |
| docs     | 仅文档                     |
| style    | 格式（不影响代码逻辑）     |
| refactor | 重构（非新功能也非修复）   |
| test     | 增加或修改测试             |
| chore    | 构建流程或辅助工具变动     |

示例：`feat(auth): 支持 OAuth2 登录`

## 开发环境

```bash
# 安装依赖
# npm install / pip install -e ".[dev]" / go mod download

# 运行测试
# npm test / pytest / go test ./...
```

## 报告 Bug / 提需求

请使用仓库提供的 **Issue 模板**（Bug report / Feature request），
填写复现步骤或动机，方便我们快速定位。

## 代码风格

- 保持与现有代码风格一致
- 新增代码需附带测试
- 通过 CI 中的 lint / format 检查

## 发布

维护者负责打 Tag 与发布，遵循 [语义化版本](https://semver.org/lang/zh-CN/)。
