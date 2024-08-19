
#                      Autor: JOÃO MARCOS RIBEIRO TOLENTINO 
#                      Sistema de Recomendação
===================================================================================
Base de dados

targets.csv: UserId:ItemId
Ex: 33ce7ee122: 34cb28c370

ratings.csv: UserId:ItemId	Rating
4baf0ac888:8b05db84f2	    3
===================================================================================

Bibliotecas permitidas:

numpy==1.19.5
pandas==1.1.5
python-dateutil==2.8.1
pytz==2020.5
six==1.15.0

Descricao do trabalho:
# normalização de dados.
# cálculo de similaridade.
# seleção de vizinhança.
# agregação de classificação. 
# redução de dimensionalidade.

DOCUMENTAÇÃO: Arquivo pdf ("relatorio.pdf")

*Arquivos CSV: ratings.csv, targets.csv
Arquivo CSV gerado: redictions.csv

==> Código modularizado, comentado, documentado e gerado um arquivo csv "predictions" com as melhores predições possíveis.
 Ou seja, com o menor RMSE possível


Plataforma utilizada: https://www.kaggle.com/competitions/recsys-20232-rc1/leaderboard


