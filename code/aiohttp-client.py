#!/usr/bin/python3

import aiohttp
import asyncio

url = 'http://webcode.me'

async def main():
    async with aiohttp.ClientSession() as session:
        async with session.get(url) as response:

            print("Status:", response.status)

            data = await response.text()
            print(data)

loop = asyncio.new_event_loop()
asyncio.set_event_loop(loop)
loop.run_until_complete(main())

async def get_async(url):
    async with aiohttp.ClientSession() as session:
        return await session.get(url)

urls = ['http://webcode.me',
        'https://httpbin.org/get',
        'https://github.com']

async def launch():

# the built-in map function, apply the get_async function to the list of URLs. The returned list is unpacked into positional arguments with the * (star) operator. If all coroutines are completed successfully, the result is an aggregate list of returned values (HTML codes).
    resps = await asyncio.gather(*map(get_async, urls))
    data = [resp.status for resp in resps]

    for status_code in data:
        print(status_code)

#The asyncio.run creates an event loop, schedules the coroutines and in the end closes the loop.

asyncio.run(launch())
