# Atividade com Algorítmo de Busca


## Medições de tempo de execução
Foram medidos os tempos de execução dos principais procedimentos envolvidos na busca sequencial indexada. Estas medições foram comparadas aos tempos de execução medidos em um procedimento de busca sequencial, no mesmo conjunto de dados.
Os valores apresentados na tabela abaixo representam a média dos intervalos de tempo de execução de cada procedimento em 3 execuções.

|Numero de elementos	|Busca Sequencial indexada | Busca Sequencial  
|---------------|-----------------------------|-----------------
|               |Ordenar\|Gerar Index\|Buscar |Buscar
|100			|73591ns \|6446ns \|6884ns  |5952ns
|200			|161129ns\|11201ns\|7860ns  |9216ns
|300			|332620ns\|17747ns\|9302ns  |12180ns	

### Conclusão
A busca sequencial indexada é mais eficiente em relação à busca sequencial simples em conjuntos maiores de elementos. Com menor quantidade de elementos os procedimentos de ordenação e de geração da tabela de índices acabam se tornando muito caros, a ponto de fazer com que a busca indexada se torne mais lenta em relação à busca sequencial simples.
