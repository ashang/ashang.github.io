

## pv

## tar

```sh
ssh remote tar -cpf - -C mydir myfiles | sudo sh -c "tar -xpf -"
ssh remote tar -cpf - -C mydir myfiles | sudo tar -xpf -
ssh remote tar -cpzf - -C mydir myfiles | sudo tar -xpzf -
```

