# minitalk

<div>
	<img align="left" alt="Minitalk" src="https://github.com/eduaserr/42-project-badges/blob/a48e677fd4871e6999a9564101dca26091ec18ef/badges/minitalkn.png" width="75px">
	<img align="right" alt="MinitalkBonus" src="https://github.com/eduaserr/42-project-badges/blob/a48e677fd4871e6999a9564101dca26091ec18ef/badges/minitalkm.png" width="75px">
	<h1 align="center"> ~MINITALK~ <br><img alt="success 125/100" src="https://img.shields.io/badge/125%2F100-green?style=plastic&logoColor=green&label=success"></h1>
</div>
<p align="center">A small data exchange program using UNIX signals. <br></p>
<div align="justify">
<code>Minitalk</code> is a project from the <b>Common Core</b> of <b>42Cursus</b> where you will learn about inter-process communication using signals in C. The objective is to create a simple communication system between two processes using the UNIX signals SIGUSR1 and SIGUSR2.
</div>

For compilation, you can use the Makefile by typing `make` followed by the desired rule command.

## Functions

Original Functions|Description
:----------------:|:----------:
`ft_send_bits`|Sends a string bit by bit to a specified PID using signals.
`main` (sender)|Processes input, retrieves the PID, and sends the bits of the given string.
`signal_handler`|Handles incoming signals and reconstructs the original message character by character.
`main` (receiver)|Initializes the receiver process, sets up signal handling, and waits for incoming signals.