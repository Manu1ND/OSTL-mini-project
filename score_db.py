import sqlite3
from sqlite3 import Error
 
 
def create_connection(db_file):
  
    conn = None
    try:
        conn = sqlite3.connect(db_file)
    except Error as e:
        print(e)
 
    return conn
 
 
def add_data(conn, data):
    
    sql = ''' INSERT INTO score(player_name,player_score,comp_score)
              VALUES(?,?,?) '''
    cur = conn.cursor()
    cur.execute(sql, data)
 
 
def save_score(player_name, player_score, comp_score):
    database = r"python.sqlite"
 
    # create a database connection
    conn = create_connection(database)
    with conn:

        data = (player_name, player_score, comp_score);
        add_data(conn, data)