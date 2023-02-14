import pymysql.cursors


def run_sql(sql):
    connection = pymysql.connect(host='localhost',
                                 port = 3306,
                                 user='root',
                                 password ='Fediun_2003', 
                                 db='travel_agency'
                                 )
    try:
        connection.commit()
        with connection.cursor() as cursor:
            cursor.execute(sql)
            connection.commit()


    finally:
        connection.close()


def show_results(sql):
    connection = pymysql.connect(host='localhost',
                                 port = 3306,
                                 user='root',
                                 password ='Fediun_2003', 
                                 db='travel_agency'
                                 )
    try:
        connection.commit()
        with connection.cursor() as cursor:
            cursor.execute(sql)
            rows = cursor.fetchall()
            desc = cursor.description

            for d in desc:
                print(f'{d[0]:<35}', end='')
            print()

            for row in rows:
                for i in range(0, len(row)):
                    print(f'{row[i]:<35}', end='')
                print()
    finally:
        connection.close()


def show_offers():
    sql = "SELECT o.id, o.name,  l.city_name AS city, c.name AS country," \
          " h.name as hotel, h.stars, o.trip_price FROM offer o " \
          "INNER JOIN location l ON o.location_id = l.id INNER JOIN country c" \
          " ON l.country_id = c.id INNER JOIN hotel h ON o.hotel_id = h.id "
    show_results(sql)
    choice = input("Do you want to narrow your search results?\n"
                   "1. Yes\n"
                   "2. No\n")
    if choice == "1":
        narrow_offer_search(sql)


def narrow_offer_search(sql):
    price = input("What price range do you choose?\n"
                   "1. Below 2000\n"
                   "2. Above 2000\n"
                   "3. Whatever\n")
    standard = input("What standard of hotel do you choose?\n"
                      "1.Hostel\n"
                      "2. 3, 4 and 5 star hotels\n"
                      "3. Whatever\n")
    price_sql = ""
    standard_sql = ""

    if price == "1":
        price_sql = "WHERE o.trip_price < 2000 "
    elif price == "2":
        price_sql = "WHERE o.trip_price > 2000 "

    sql += price_sql

    if price == "3" and (standard == "1" or standard == "2"):
        sql += "WHERE "
    elif price != "3" and (standard == "1" or standard == "2"):
        sql += "AND "
    if standard == "1":
        standard_sql += "h.stars = 0"
    elif standard == "2":
        standard_sql += "h.stars IN (\"3\",\"4\",\"5\")"

    sql += standard_sql

    show_results(sql)

def delete_offer():
    id_ = input("Enter trip id: ")
    sql = f"DELETE FROM offer WHERE id = '{id_}'"
    run_sql(sql)
    show_offers()


def show_client_info():
    sql = "SELECT * FROM `client`"
    show_results(sql)


def show_your_info(id_):
    sql = f"SELECT * FROM `client` WHERE id = \"{id_}\""
    show_results(sql)


def add_client():
    id_ = input("Enter new customer id: ")
    full_name = input("Enter your first and last name: ")
    phone_number = input("Give me your phone number: ")
    sql = f"INSERT INTO client (id, full_name, phone_number) " \
          f"VALUES ('{id_}', '{full_name}', '{phone_number}')"
    run_sql(sql)
    show_client_info()


def delete_client():
    id_ = input("Enter customer id: ")
    sql = f"DELETE FROM client WHERE id = '{id_}'"
    run_sql(sql)
    show_client_info()