import numpy as np
import pandas as pd

def load_data():
    # Carrega os arquivos.
    ratings_df = pd.read_csv('ratings.csv', encoding='latin-1', sep=',|:', engine='python')
    targets_df = pd.read_csv('targets.csv', sep=':', engine='python')
    return ratings_df, targets_df

def preprocess_data(ratings_df):
    # Calcula a média dos ratings.
    mean_rating = ratings_df['Rating'].mean()

    # Extrai as colunas e armazena em listas.
    users = list(ratings_df['UserId'])
    items = list(ratings_df['ItemId'])
    ratings = list(ratings_df['Rating'])

    # Cria listas de IDs únicos.
    user_ids = list(set(users)) 
    item_ids = list(set(items))

    # Calcula o número de usuários e itens únicos.
    num_users = len(user_ids)
    num_items = len(item_ids)

    # Cria dicionários que mapeiam IDs de usuário e item para índices.
    user_index = {user_id: index for index, user_id in enumerate(user_ids)}
    item_index = {item_id: index for index, item_id in enumerate(item_ids)}

    # Cria uma matriz de zeros para armazenar as classificações.
    ratings_matrix = np.zeros((num_users, num_items))

    # Preenche a matriz de classificação com as classificações fornecidas.
    for i in range(len(users)):
        user = users[i]
        item = items[i]
        rating = ratings[i]
        user_idx = user_index[user]
        item_idx = item_index[item]
        ratings_matrix[user_idx][item_idx] = rating

    return ratings_matrix, user_index, item_index, mean_rating

def train_model(ratings_df, ratings_matrix, user_index, item_index, mean_rating):
    # Extrai as colunas e armazena em listas.
    users = list(ratings_df['UserId'])
    items = list(ratings_df['ItemId'])
    ratings = list(ratings_df['Rating'])

    # Define hiperparâmetros do modelo
    num_factors = 15
    learning_rate = 0.01
    regularization = 0.2
    num_epochs = 20

    # Inicializa aleatoriamente as matrizes de fatores latentes.
    num_users, num_items = ratings_matrix.shape
    user_factors = np.random.rand(num_users, num_factors)
    item_factors = np.random.rand(num_items, num_factors)

    for epoch in range(num_epochs):
        for i in range(len(users)):
            user = users[i]
            item = items[i]
            rating = ratings[i]
            user_idx = user_index[user]
            item_idx = item_index[item]

            # Calcula a correção de viés.
            bias_correction = (np.dot(user_factors[user_idx], item_factors[item_idx]) - mean_rating)

            # Calcula a previsão com a correção de viés.
            prediction = np.dot(user_factors[user_idx], item_factors[item_idx]) + bias_correction

            error = rating - prediction

            user_factors[user_idx] += learning_rate * (error * item_factors[item_idx] - regularization * user_factors[user_idx])
            item_factors[item_idx] += learning_rate * (error * user_factors[user_idx] - regularization * item_factors[item_idx])

    return user_factors, item_factors

def make_predictions(user_factors, item_factors, user_index, item_index, targets_df):
    # Cria um DataFrame vazio para armazenar as previsões.
    predictions_df = pd.DataFrame(columns=["UserId:ItemId", "Rating"])

    # Itera sobre os dados de destino e obtém os IDs de usuário e item.
    for index, row in targets_df.iterrows():
        user_id = row['UserId']
        item_id = row['ItemId']
        user_idx = user_index.get(user_id)
        item_idx = item_index.get(item_id)

        if user_idx is not None and item_idx is not None:
            # Calcula a previsão para o par usuário-item atual.
            prediction = np.dot(user_factors[user_idx], item_factors[item_idx])
            predictions_df = predictions_df.append({"UserId:ItemId": f"{user_id}:{item_id}", "Rating": prediction}, ignore_index=True)
        else:
            print(f"{user_id}:{item_id}, Usuário ou item não encontrado")

    return predictions_df

def save_predictions(predictions_df):
    # Salva as previsões em um arquivo CSV.
    predictions_df.to_csv("predictions.csv", index=False)
    print("Previsões salvas com sucesso em predictions.csv")

def main():
    # Carrega os dados de classificação e destino
    ratings_df, targets_df = load_data()
    # Pré-processa os dados de classificação para criar uma matriz de classificação e outros índices
    ratings_matrix, user_index, item_index, mean_rating = preprocess_data(ratings_df)
    # Treina o modelo de recomendação com base nos dados de classificação
    user_factors, item_factors = train_model(ratings_df, ratings_matrix, user_index, item_index, mean_rating)
    # Faz previsões usando o modelo treinado e os dados de destino
    predictions_df = make_predictions(user_factors, item_factors, user_index, item_index, targets_df)
     # Salva as previsões em um arquivo CSV 
    save_predictions(predictions_df)

if __name__ == "__main__":
    main()
