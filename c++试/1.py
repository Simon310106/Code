import random

def game():
    while True:
        number_to_guess = random.randint(1, 10)
        
        while True:
            user_number = int(input("请输入你猜测的数字 (1-10): "))
            
            if user_number == number_to_guess:
                print("恭喜，你猜对了！")
                break
            elif user_number < number_to_guess:
                print("太低了，再试一次。")
            else:
                print("太高了，再试一次。")
        
        play_again = input("你要再玩一局吗？(yes/no): ")
        if play_again.lower() != "yes":
            break
            
if __name__ == '__main__':
    game()