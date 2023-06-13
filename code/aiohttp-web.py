#!/usr/bin/python3

from aiohttp import web
routes = web.RouteTableDef()

async def home(req):
    return web.Response(text="home page")

@routes.get('/')
async def home(request):
    return web.Response(text="home page")

@routes.get('/users')
async def users(req):
    users = [{'name': 'John Doe', 'email': 'john.doe@example.org'},
            {'name': 'Roger Roe', 'email': 'roger.roe@example.org'}]
    return web.json_response(users)

app = web.Application()
#app.add_routes([web.get('/', home)])
app.add_routes(routes)

web.run_app(app)
