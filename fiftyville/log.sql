-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find ID of situation: 295
-- Points to 2 interviews taken connected to case
-- Points to date of 07-28-2021
-- 10:15 AM
SELECT * FROM crime_scene_reports WHERE id = '295';

-- Link to interviews based on date
-- ID 162, 163 are relevant interviews

-- Interview 2
    -- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

-- Interview 1
    -- "As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
    --  In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket."
SELECT * FROM interviews WHERE day = '28' AND month = '7' and year = '2021';

-- Link ATM withdrawal to possible suspect
SELECT * FROM atm_transactions WHERE atm_location = 'Leggett Street' AND transaction_type = 'withdraw' AND day = '28' AND month = '7' and year = '2021';

-- Link to Bakery Security Logs
SELECT license_plate FROM bakery_security_logs WHERE year = '2021' AND day = '28' AND month = '7' and HOUR >= '10' and HOUR <= '11';

-- Link to bank accounts
SELECT * FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street' AND transaction_type = 'withdraw' AND day = '28' AND month = '7' and year = '2021');

-- Link to flights
-- Found id 36 based on date and earliest departure
SELECT * FROM flights WHERE id = '36';

-- Link to Phone Calls
SELECT caller FROM phone_calls WHERE year = '2021' AND day = '28' AND month = '7' AND duration <= 60;

-- Link to airports
SELECT * FROM airports WHERE id = 4;

-- Link to Passengers
SELECT * FROM passengers WHERE flight_id = '36';

-- Link to People based on all the found values
SELECT * FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE year = '2021' AND day = '28' AND month = '7' and HOUR = '10' and minute <= 30) AND passport_number IN
(SELECT passport_number FROM passengers WHERE flight_id = '36') AND phone_number IN
(SELECT caller FROM phone_calls WHERE year = '2021' AND day = '28' AND month = '7' AND duration <= 60) AND id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street' AND transaction_type = 'withdraw' AND day = '28' AND month = '7' and year = '2021'));

-- Bruce called who?
SELECT * FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE year = '2021' AND day = '28' AND month = '7' AND duration <= 60 AND caller = '(367) 555-5533');

