func evalRPN(tokens []string) int {
	//number push to stack, operator pop from stack and do operation, take result and add to stack
	stackRPN := []int{}
	second, first, res := 0, 0, 0

	for i := 0; i < len(tokens); i++ {
		if tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/" && tokens[i] != "*" {
			num, err := strconv.Atoi(tokens[i])
			if err == nil {
				stackRPN = append(stackRPN, num)
			} else {
				fmt.Println("Error converting token to integer:", err)
			}
		} else {
			second = stackRPN[len(stackRPN)-1]
			stackRPN = stackRPN[:len(stackRPN)-1]
			first = stackRPN[len(stackRPN)-1]
			stackRPN = stackRPN[:len(stackRPN)-1]
			switch tokens[i] {
			case "+":
				res = first + second
			case "-":
				res = first - second
			case "*":
				res = first * second
			case "/":
				if second != 0 {
					res = first / second
				} else {
					fmt.Println("Error: Division by zero")
					continue
				}
			default:
				fmt.Println("Invalid operator")
				continue
			}
            stackRPN = append(stackRPN, res)

		}
	}
    return stackRPN[len(stackRPN)-1]
}