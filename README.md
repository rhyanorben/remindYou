# Remind You - Calendário de Eventos

Sistema desenvolvido na linguagem de programação **C** para organizar os seus eventos.

### Menu Principal

1. [Adicionar evento](#adicionar-evento)
2. [Editar evento](#editar-evento)
3. [Localizar](#localizar)
4. [Excluir evento](#excluir-evento)
5. [Sair](#sair)

#### 1. Adicionar evento <a name="adicionar-evento"></a>

Tela para adicionar um novo evento no programa.

As informações para cadastro são:

- Nome do evento.
- Descrição do evento.
- Data (DD/MM/AAAA).
- Hora do Evento.
- Estoque inicial.

Todos os campos são de preenchimento obrigatório para funcionamento correto do programa, porém ainda não é realizado uma conferência de preenchimento destes dados.

### 2. Editar evento <a name="editar-evento"></a>

A tela primeiramente permite você localizar o evento que deseja editar pela data.

Essa data é informada no formato "DD MM AAAA", tendo que informar perfeitamente os dados utilizados para encontrar a info.
Ainda não possui uma verificação de dados incorreto nessa parte.

Ao localizar pela data, é informado o ID do evento gerado pelo indice dele(+1) na "Struct".  

É possível ao informar o ID:

- Alterar nome
- Alterar descricao
- Alterar hora
- Cancelar

### 3. Localizar <a name="localizar"></a>

Tela usada para localizar os eventos armazenados no código, a partir da data.

Essa data é informada no formato "DD MM AAAA", tendo que informar perfeitamente os dados utilizados para encontrar a info.
Ainda não possui uma verificação de dados incorreto nessa parte.

### 4. Excluir evento <a name="excluir-evento"></a>

Utiliza novamente a função de "localizar", para encontrar o evento pela data.

Ao encontrar o evento você visualiza o ID dele e informa o mesmo para realizar exclusão.

- Ao informar um ID que não existe o sistema retorna "ID inválido" e retorna ao menu principal.
- Ao informar um ID válido, ele realiza a exclusão do evento e reorganiza o ID de todos os outros existentes para uma nova sequência ordenada.  

### 5. Sair <a name="sair"></a>

Apenas fecha o programa.
