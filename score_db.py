import sqlite3
from sqlite3 import Error
 
 
def create_connection(db_file):
    """ create a database connection to the SQLite database
        specified by db_file
    :param db_file: database file
    :return: Connection object or None
    """
    conn = None
    try:
        conn = sqlite3.connect(db_file)
    except Error as e:
        print(e)
 
    return conn
 
 
def add_data(conn, data):
    """
    Create a new project into the projects table
    :param conn:
    :param project:
    :return: project id
    """
    sql = ''' INSERT INTO score(player_name,player_score,comp_score)
              VALUES(?,?,?) '''
    cur = conn.cursor()
    cur.execute(sql, data)
 
 
def save_score(player_name, player_score, comp_score):
    database = r"python.sqlite"
 
    # create a database connection
    conn = create_connection(database)
    with conn:
        # create a new project
        data = (player_name, player_score, comp_score);
        add_data(conn, data)