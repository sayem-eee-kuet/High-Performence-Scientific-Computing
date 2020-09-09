def monteCarloIntigration(N):  # N = Number of random point

    random()  # Random Number Initilization
    
    I = 0.0  # intergral initialization

    # summation calculation
    for i in range(N):
        # Randmon number from the interval
        x = draw a random number from [-1, 1]  
        f = 1/(1+x*x)
        I = I + f(x)
    end	

    #final calculation
    I = 2 * (1 / N) * I  # Volume, V = 2
    
    # Error calculation
    abserrorCal()

end    
