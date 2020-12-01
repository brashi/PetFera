<h1 align="center">
  <br>
  <img src="https://github.com/brashi/PetFera/blob/main/docs/logo.png?raw=true" alt="PetFera" width="200">
  <br>
  PetFera
</h1>
<h4 align="center">Loja que comercializa animais silvestres com os devidos cuidados e autorizações do <a href="https://www.gov.br/ibama/pt-br">IBAMA</a>.</h4>

<p align="center">
<i>Projeto realizado para a matéria de Linguagem de Programação I (UFRN)</i>
</p>

<p align="center">
  <a href="#funcionalidades">Funcionalidades</a> •
  <a href="#como-usar">Como Utilizar</a> •
  <a href="#documentação">Documentação</a> •
  <a href="#créditos">Créditos</a> •
  <a href="#ferramentas">Ferramentas</a> •
  <a href="#licença">Licença</a>
</p>

![screenshot](https://github.com/brashi/PetFera/blob/main/docs/capa.png?raw=true)


## Funcionalidades
* Cadastro, alteração, listagem
  - Animais
  - Veterinários
  - Tratadores
* Sistema de permissão de manejo (tratadores)
* Filtragem de animais por classe, classificação, tratador ou veterinário

## Como usar
É sempre possível [baixar](https://github.com/brashi/PetFera/releases) o binário da versão mais recente publicada na [página de releases](https://github.com/brashi/PetFera/releases), entretanto, caso queira `clone` o projeto para usar, deverá seguir o seguinte passo a passo:

```bash
# Certifique-se que tem o g++ e o make instalados, caso não tenha, realizar:
$ sudo apt-get install g++
$ sudo apt-get install make

# Ou (ubuntu apenas):
$ sudo apt-get install build-essential

# Clone do projeto (URL do repositório)
$ git clone https://github.com/brashi/PetFera.git

# Dentro da pasta do projeto, execute um make para realizar a compilação do mesmo
$ make

# Caso queira instâncias predefinidas de animais, veterinários e tratadores para testes digite:
$ make debug

# Use o comando abaixo para assegurar que saiu do modo debug
$ make clean

# Caso queira apenas recompilar os arquivos-objetos, use:
$ make remake

# Agora execute o programa normalmente
$ ./petFera
```

*Comandos úteis:*
- `make clean` Apaga arquivos de dependências e arquivos-objetos
- `make remake` Apaga apenas arquivos-objetos, mantendo os arquivos de dependências

## Documentação
Para acessar a documentação, visite: [Documentação PetFera](https://brashi.github.io/PetFera)

## Créditos
O projeto foi feito em **dupla**. Sendo os participantes:

* [Lauro Bezerra de Araújo](https://github.com/brashi)
* [Lucas Moura do Nascimento](https://github.com/lluckymou)

## Ferramentas
As ferramentas utilizadas foram:
* `c++14` linguagem de programação
* `make 4.2.1-1.2` para o make
* `g++ 4:8.3.0-1` ([Lauro](https://github.com/brashi)) e `4:9.3.0-1ubuntu2` ([Lucas](https://github.com/lluckymou))
* [Visual Studio Code](https://github.com/microsoft/vscode) para desenvolvimento

Sistemas operacionais utilizados:
- Debian ([Lauro](https://github.com/brashi))
- Ubuntu 20.04 WSL (Windows 10) ([Lucas](https://github.com/lluckymou))

## Licença
PetFera utiliza a licença [MIT](https://github.com/brashi/PetFera/blob/main/LICENSE).
