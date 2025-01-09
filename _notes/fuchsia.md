## fuchsia

```shell
rm -rf .jiri_manifest .jiri_root integration
curl -s https://fuchsia.googlesource.com/jiri/+/master/scripts/bootstrap_jiri?format=TEXT | base64 --decode | bash -s ${PWD}
jiri init -keep-git-hooks=true
jiri import -name=integration flower https://fuchsia.googlesource.com/integration
jiri update -v
```

https://zhuanlan.zhihu.com/p/337740825

https://zhuanlan.zhihu.com/p/67579127
