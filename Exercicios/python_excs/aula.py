# nome = 'Joao'
# estado = True
# custoBolo=98


# # Funcao type()
# print(type(nome))
# print(type(custoBolo))

# # Funcao isInstance()
# a = 10
# b = 'sol'

# print(isinstance(a, int))  # T
# print(isinstance(b, str))  # T
# print(isinstance(a, str))  # F
# print(isinstance(a, (int, float))) #T

# a = 40
# b = 2
# result = a*b
# print(result)

# x = y = z = 0

# print('Digite um numero:')      
# n1 = int(input())
# n2 = int (input('Digite o numero:'))

# x=n1==n2
# print('Sao iguais?', x, '\n')


# Comparacao

# z = n1 > n2
# print(n1, 'eh maior que', n2, '? ', z, '\n')

# idade=15
# altura=1.75
# resultado = (idade >= 18) and (altura) >= 1.7
# msg='Para o RESULTADO eh: v ou f? ' + str(resultado)
# print(msg)



# a=10
# b=5
# result=f'a soma de {a} com {b} eh: {a+b}'
# print(result)


# nome = None #vazia

# while True:
#     print('Digite seu nome (X para parar):')
#     nome=input()

#     if(nome.upper() == 'X'):
#         break
#     print(f'Bem-vindo, {nome}')
# print("Tchau")


# lista= [2, 3, 3, 444, 6, 777, 0, 2, 1, 123, 12]
# palavra = 'Boston'


# for letra in palavra:
#     print(letra)


# gera numeros de 1 a 10
for numero in range(1, 11):
    print(numero)



nome= input('DIgite seu nome:')
for x in range(10):
    print(f'{x+1} {nome}')


# Cria os numeros de 2 em 2 (indo de 2 ate 20):
for x in range(2, 20, 2):
    print(x)
