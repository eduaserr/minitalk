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

## Description

The Minitalk program consists of two components: a **server** and a **client**. This project allows you to learn about inter-process communication using signals in C.

## Using the Minitalk Program

### 1. Start the Server

To start the server, simply run the program without any arguments. This will cause the server to print its PID (process identifier) and begin waiting for signals from a client.

	./server

	PID : 1234567
	waiting...

### 2. Start the Client

For the client, you need to provide the PID of the server and the string you want to send. The client will take these arguments from the command line.

	./minitalk_client 1234567 "Hello"

### Signal Processing
1. In the Client:

* The client converts each character of the string to its binary form.
* For each bit:
	* Sends SIGUSR2 for 1.
	* Sends SIGUSR1 for 0.
* Uses usleep(200) to ensure proper timing between signals.
2. In the Server:

* The server sets up signal handlers for SIGUSR1 and SIGUSR2.
* Upon receiving a signal, it updates a character (chr) based on the bit:
	* Sets the bit to 1 for SIGUSR2.
	* Leaves it unchanged for SIGUSR1.
* After receiving 8 bits (a complete byte), it prints the character and resets for the next byte.

For compilation, you can use the Makefile by typing `make` followed by the desired rule command.

## Functions

Original Functions|Description
:----------------:|:----------
`ft_send_bits`|Sends a string bit by bit to a specified PID using signals.
`main` (sender)|Processes input, retrieves the PID, and sends the bits of the given string.
`signal_handler`|Handles incoming signals and reconstructs the original message character by character.
`main` (receiver)|Initializes the receiver process, sets up signal handling, and waits for incoming signals.