---
**Author:** Adrián Moreno Monterde

**Title:** Markov Decision Process Model-Free prediction with Monte-Carlo Learning

**Date:** 04/02/2021

**Email:** adrian.moreno.mon@gmail.com

# Markov Decision Process Model-Free prediction with Monte-Carlo Learning
## Monte-Carlo Learning
### What is Monte-Carlo Learning?
- The Monte Carlo method is a simulation method for mathematical models that consists of generating random numbers and seeing if they have obtained one result or another within the probabilities of the model and from there draw conclusions taking into account that the more simulations the lower the error will be.
- The method was named in reference to the "Monte Carlo Casino" , being the roulette a simple random number generator.
- It is a non-deterministic or statistical numerical method, used to approximate complex mathematical expressions that present some type of computational difficulty to evaluate them accurately.
- It is a quantitative technique that makes use of statistics to imitate the random behavior of real non-dynamic systems.

### Monte-Carlo Policy Evaluation
The goal is that given a policy $\pi$, learn $v\pi$ (value for the policy) based on episodes of experience.
Monte-Carlo policy evaluation uses empirical mean return instead of expected return. There are to ways to evaluate the value function of a policy at a state:

- First-Visit Monte-Carlo Policy Evaluation

    1. Evaluate the value of state s of a given policy.

    2. The **first** time-step (t) that state (s) is visited in an episode.
    
    3. Increment the counter: $N(s) \leftarrow N(s)+1$

    4. Increment the total return: $S(s) \leftarrow S(s)+G_t$

    5. Value is estimated by mean return: $V = S(s)/N(s)$

    6. $V(s) \rightarrow v\pi (s)$ as $N(s) \rightarrow \infty$

- Every-Visit Monte-Carlo Policy Evaluation

    1. Evaluate the value of state s of a given policy.

    2. **Every** time-step (t) that state (s) is visited in an episode.

    3. Increment the counter: $N(s) \leftarrow N(s)+1$

    4. Increment the total return: $S(s) \leftarrow S(s)+G_t$

    5. Value is estimated by mean return: $V = S(s)/N(s)$

    6. $V(s) \rightarrow v (s)$ as $N(s) \rightarrow \infty$

In both evaluations we have the same problem: we can only compute after we have completed all the episodes. To solve it we can use the *Incremental Mean* equation to update the value incrementally which is the following formula: 

$$
    \mu_k = \mu_{k-1} + \frac{1}{k} (x_k - \mu_{k-1})
$$

Relating it to the Monte-Carlo method we have the following formulas:

$$
    N(S_t) \leftarrow N(S_t) + 1
$$

$$
    V(S_t) \leftarrow + \frac{1}{N(S_t)} (G_t - V(S_t))
$$

## Monte-Carlo methods via Markov chains 
- Monte-Carlo Markov Chain Methods (MCMC) are simulation methods for generating samples of the posterior distributions and estimating quantities of interest posteriorly.
- In MCMC methods, values of a proposed density are simulated successively, which does not necessarily have to be similar to the posterior density.
- Each generated value depends only on the previous simulated value, hence the notion of a Markov chain.

### Basic ideas about MCMC methods
- Suppose we want to simulate the values of a posterior distribution $\pi(\theta | x)$.
- The idea of MCMC methods is to simulate a Markov chain $\theta_1 , \theta_2 , ...$ whose stationary distribution is $\pi(\theta | x)$.
- Each simulated value, $\theta_t$, depends solely on its predecessor, $\theta_{t-1}$.
- If the algorithm is implemented correctly, the convergence of the chain is guaranteed regardless of what the initial values are. 

## Markov Chains Monte-Carlo Algorithms

There are many algorithms that implement MCMC but the ones that must be mentioned by importance are: *Gibbs Sampling Algorithm* and its more general version *Metropolis-Hastings Algorithm*

### Gibbs Sampling Algorithm
- The Gibbs sampling algorithm is used to construct a Markov chain where the probability of the next sample is calculated as the conditional probability given the previous sample.
- The samples are constructed by changing one random variable at a time, which means that subsequent samples are very close in the search space. Keep in mind that there is some risk of the chain binding.
- Gibbs sampling is ideal for those probabilistic models whose conditional probability can be calculated.

### Metropilis-Hastings Algorithm
- Like the Gibbs Sampling algorithm, this algorithm is appropriate for probabilistic models where we cannot directly sample the probability distribution of the next state. It should also be noted that this algorithm is more general and flexible than the one previously explained.
- However, the Metropolis-Hastings algorithm requires the use of a proposed or surrogate probability distribution that is sampled (called the kernel) and then an acceptance criterion, which decides whether the new sample is accepted into the chain or discarded.
- This acceptance criterion is probabilistic based on the probability that the distribution of the proposal differs from the true probability distribution of the next state.

# Example of simple Markov Chain with Monte Carlo Learning

Given:

- $P(S_{t+1}|R_t) = 0.5\rightarrow$ Probability of sunny tomorrow with rain today
- $P(R_{t+1}|R_t) = 0.5\rightarrow$ Probability of rain tomorrow with rain today
- $P(R_{t+1}|S_t) = 0.1\rightarrow$ Probability of rain tomorrow with sunny today
- $P(S_{t+1}|S_t) = 0.9\rightarrow$ Probability of sunny tomorrow with sunny today

What is the probability of sunny (S) and rainy (R) weather?

These probabilities meet the following characteristics:

 - **Markov property** because futre state only depends on current state
 - **Irreducible** because must be a positive probability to go from one to any other state
 - **Aperiodic** because can't get trapped in cycles

Picking two randoms states we are going to simulate two markov chains: 

  - Markov chain #1: S-S-R-R-S-S-S-S-S-R-R-R-S-S-S
  - Markov chain #2: R-S-S-S-S-S-R-S-S-S-S-S-S-R-R
  - Markov chain #n : ...

If we were to simulate multiple chains with enough samples, we would obtain as global values that $P(S)=0.833$ and $P(R)=0.167$ which would be the ideal probabilities for this example shown. 

# Conclusion
With this article we have learned that MonteCarlo is a learning algorithm, which is used in markov chains and allows us to obtain global probabilities through sampling. It should be noted that the precision in the value and the number of samples are directly proportional.

## Bibliography:
- https://www.youtube.com/watch?v=LI38DSFBcKk&list=LL&index=2
- https://towardsdatascience.com/model-free-prediction-reinforcement-learning-507297e8e2ad
- https://machinelearningmastery.com/markov-chain-monte-carlo-for-probability/ 
- https://www.youtube.com/watch?v=7QX-yVboLhk 