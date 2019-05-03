"use strict";

var Color = {
    pink: "#DD1772",
    darkblue: "#281A71",
    lightblue: "#0093DD",
    blue: "#1B7EE0",
    dblue: "#1560AB",
    lblue: "#1F90FF",
    red: "#E01B53",
    green: "#C6FF40"
};

var CTX;

var HCI;

var Net;

var newHost;

var newLink;

var Rand = function(max, min) {
    min = min || (max -= 1, 0);
    return Math.floor(Math.random() * (max - min + 1) + min);
};

var UI = {};

"use strict";

HCI = function() {
    var x0, y0;
    var x, y;
    var hovered;
    var state = {
        drag: false,
        select: false,
        balanceLoad: false,
        mousemove: false
    };
    var key = {
        code: {
            Enter: 13,
            Shift: 16,
            Ctrl: 17,
            Alt: 18,
            Esc: 27,
            Space: 32,
            Meta: 91,
            Left: 37,
            Up: 38,
            Right: 39,
            Down: 40,
            "0": 48,
            "1": 49,
            "2": 50,
            "3": 51,
            "4": 52,
            "5": 53,
            "6": 54,
            "7": 55,
            "8": 56,
            "9": 57,
            A: 65,
            B: 66,
            C: 67,
            D: 68,
            E: 69,
            F: 70,
            G: 71,
            H: 72,
            I: 73,
            J: 74,
            K: 75,
            L: 76,
            M: 77,
            N: 78,
            O: 79,
            P: 80,
            Q: 81,
            R: 82,
            S: 83,
            T: 84,
            U: 85,
            V: 86,
            W: 87,
            X: 88,
            Y: 89,
            Z: 90,
            ";": 186,
            "=": 187,
            ",": 188,
            "-": 189,
            ".": 190,
            "/": 191,
            "`": 192,
            "[": 219,
            "\\": 220,
            "]": 221,
            "'": 222
        }
    };
    return {
        state: state,
        key: key,
        getHovered: getHovered,
        init: init,
        draw: draw
    };
    function init() {
        x0 = UI.canvas.getBoundingClientRect().left;
        y0 = UI.canvas.getBoundingClientRect().top;
        window.onkeydown = onKeyDown;
        window.onkeyup = onKeyUp;
        UI.canvas.onmouseup = onMouseUp;
        UI.canvas.onmousedown = onMouseDown;
        UI.canvas.onmousemove = onMouseMove;
    }
    function onMouseDown(event) {
        x = event.clientX - x0;
        y = event.clientY - y0;
        UI.menu.style.display = "none";
        if (event.button === 0) {
            key.mouse1 = true;
        }
        if (event.button === 2) {
            key.mouse2 = true;
        }
        hovered = hover(x, y);
        if (event.button === 0) {
            if (hovered) {
                if (hovered.type === "host" || hovered.type === "router") {
                    state.drag = {
                        x: x,
                        y: y
                    };
                    UI.canvas.onmousemove = drag;
                    UI.setStyle(UI.canvas, "cursor", "grabbing");
                }
            } else {
                state.select = {
                    x: x,
                    y: y,
                    dx: 0,
                    dy: 0,
                    any: false
                };
                UI.canvas.onmousemove = select;
            }
        } else if (event.button === 2) {
            event.preventDefault();
            clear();
            if (hovered) {
                UI.showMenu(hovered, x, y);
            }
        }
    }
    function onMouseUp(event) {
        if (state.drag) {
            state.drag = false;
            UI.canvas.onmousemove = onMouseMove;
            UI.canvas.style.cursor = "auto";
            hovered = hover(event.clientX - x0, event.clientY - y0);
            var req = new Object();
            req.x_coord = hovered.x;
            req.y_coord = hovered.y;
            Server.ajax("PUT", "api/webui/coord/" + hovered.id, req);
        } else if (state.select) {
            UI.canvas.onmousemove = onMouseMove;
            if (state.select.any) {
                state.select = false;
                return;
            }
            state.select = false;
        }
        if (event.button === 0) {
            key.mouse1 = false;
            x = event.clientX;
            y = event.clientY;
        }
        if (event.button === 2) {
            key.mouse2 = false;
            UI.aux.style.display = "none";
        }
        if (!key.ctrl) {
            clear();
        }
    }
    function onMouseMove(event) {
        var i, len, t, w, h, x = event.clientX - x0, y = event.clientY - y0;
        state.mousemove = true;
        UI.canvas.style.cursor = "auto";
        state.mousemove = false;
        return;
    }
    function onKeyDown(event) {
        if (event.keyCode === key.code.N) {
            key.n = true;
        } else if (event.keyCode === key.code.G) {
            key.g = true;
        } else if (event.keyCode === key.code.Alt) {
            key.alt = true;
        } else if (event.keyCode === key.code.S) {
            key.s = true;
        } else if (event.keyCode === key.code.L) {
            key.l = true;
        } else if (event.keyCode === key.code.Ctrl) {
            key.ctrl = true;
        } else if (event.keyCode === key.code.Z) {
            key.z = true;
        } else if (event.keyCode === key.code.Esc) {
            clear();
            UI.menu.style.display = "none";
            UI.aux.style.display = "none";
        } else if (event.keyCode === key.code.Enter) {
            key.enter = true;
            if (UI.aux.style.display != "none") {
                var button = UI.aux.querySelector("button.new");
                if (button.style.top && button.style.display != "none") {
                    UI.addRule();
                }
            }
        }
    }
    function onKeyUp(event) {
        if (event.keyCode === key.code.N) {
            key.n = false;
        } else if (event.keyCode === key.code.Alt) {
            key.alt = false;
        } else if (event.keyCode === key.code.S) {
            key.s = false;
            clear();
        } else if (event.keyCode === key.code.G) {
            key.g = false;
        } else if (event.keyCode === key.code.Ctrl) {
            key.ctrl = false;
        } else if (event.keyCode === key.code.L) {
            key.l = false;
        } else if (event.keyCode === key.code.Z) {
            key.z = false;
        } else if (event.keyCode === key.code.Esc) {
            key.enter = false;
        }
    }
    function hover(x, y, dx, dy) {
        var i, len, j, t;
        if (arguments.length === 2) {
            for (i = Net.hosts.length - 1; i >= 0; --i) {
                if (Net.hosts[i].isOver(x, y)) {
                    return Net.hosts[i];
                }
            }
            if (key.mouse2 || key.ctrl) {
                for (i = Net.links.length - 1; i >= 0; --i) {
                    if (Net.links[i].isOver(x, y)) {
                        if (state.balanceLoad && state.balanceLoad.type === "router") {
                            t = 0;
                            for (j = 0, len = state.balanceLoad.links.length; j < len; ++j) {
                                if (state.balanceLoad.links[j].isSelected) {
                                    t += 1;
                                }
                            }
                            if (t > 1) {
                                UI.showMenu(Net.links[i], x, y);
                            }
                        }
                        return Net.links[i];
                    }
                }
            }
            return false;
        } else {
            state.select.any = false;
            for (i = Net.hosts.length; i--; ) {
                Net.hosts[i].isSelected = false;
                if (Net.hosts[i].isOver(x, y, dx, dy)) {
                    state.select.any = true;
                }
            }
        }
    }
    function drag(event) {
        var i, host;
        var dx = event.clientX - x0 - state.drag.x;
        var dy = event.clientY - y0 - state.drag.y;
        state.drag.x += dx;
        state.drag.y += dy;
        for (i = Net.hosts.length - 1; i >= 0; --i) {
            host = Net.hosts[i];
            if (host.isSelected) {
                host.x += dx;
                host.y += dy;
                Net.save();
            }
        }
    }
    function select(event) {
        var dx = event.clientX - x0 - state.select.x;
        var dy = event.clientY - y0 - state.select.y;
        state.select.dx = dx;
        state.select.dy = dy;
        hover(state.select.x, state.select.y, state.select.dx, state.select.dy);
    }
    function clear() {
        var i;
        for (i = Net.hosts.length - 1; i >= 0; --i) {
            Net.hosts[i].isSelected = false;
        }
        for (i = Net.links.length - 1; i >= 0; --i) {
            Net.links[i].isSelected = false;
        }
        state.balanceLoad = false;
    }
    function draw(when) {
        if (when === "before") {} else if (when === "after") {
            if (state.select) {
                CTX.lineWidth = 1;
                CTX.strokeStyle = key.g ? Color.lightblue : Color.darkblue;
                CTX.strokeRect(state.select.x, state.select.y, state.select.dx, state.select.dy);
            }
        }
    }
    function getHovered() {
        return hovered;
    }
}();

"use strict";

newHost = function() {
    return function(_) {
        _ = _ || {};
        var host = {
            type: _.icon === "router" ? "router" : "host",
            id: _.id || "DEFAULT",
            icon: _.icon || "aimac",
            ip: _.ip || "",
            name: _.name || "host",
            s: _.s || 64,
            x: _.x || Math.floor(Math.random() * 800),
            y: _.y || Math.floor(Math.random() * 400),
            color: "white",
            isSelected: false,
            links: [],
            computeLoad: computeLoad,
            draw: draw,
            isOver: isOver,
            fixed_pos: false,
            getLinksLoad: getLinksLoad
        };
        Net.add(host);
        if (host.type === "router") {
            host.firewall = false;
            host.loadBalancer = false;
            host.balancingRules = [];
            host.routingRules = new Map();
            getLinksLoad(host.id);
        }
        return host;
    };
    function delay(f, ms) {
        return function() {
            var newArr = [].slice.call(arguments);
            setTimeout(function() {
                f.apply(this, newArr);
            }, ms);
        };
    }
    function getLinksLoad(id) {
        Server.ajax("GET", "/api/switch-stats/port/" + id + "/all", setLoad);
        function setLoad(response) {
            for (var i = 0, len = response.length; i < len; ++i) {
                if (response[i].port_no <= 0) continue;
                var link = Net.getLinkByPort(id, response[i].port_no);
                if (link) {
                    link.load = parseInt(response[i].tx_byte_speed) + parseInt(response[i].rx_byte_speed);
                }
            }
        }
        if (Net.getHostByID(id)) {
            var again = delay(getLinksLoad, 2e3);
            again(id);
        }
    }
    function draw() {
        var x, y, s, r;
        CTX.save();
        CTX.translate(this.x, this.y);
        CTX.beginPath();
        if (this.icon === "router") {
            CTX.fillStyle = this.color;
            CTX.arc(0, 0, this.s / 2, 0, 2 * Math.PI);
            CTX.fill();
            this.computeLoad();
        }
        CTX.drawImage(UI.icons[this.icon].img, -this.s / 2, -this.s / 2, this.s, this.s);
        if (this.isSelected) {
            CTX.lineWidth = 1;
            CTX.strokeStyle = Color.pink;
            CTX.strokeRect(-this.s / 2, -this.s / 2, this.s, this.s);
        }
        if (this.firewall || this.loadBalancer) {
            s = this.s / 3;
            r = Math.sqrt(s / 2 * s / 2 + s / 2 * s / 2);
            x = -this.s / 2 + r / 2;
            y = -this.s / 2 + r / 2;
            CTX.font = s + "px FontAwesome";
            CTX.fillStyle = Color.blue;
            CTX.strokeStyle = Color.dblue;
            CTX.lineWidth = 3;
            if (this.firewall) {
                CTX.beginPath();
                CTX.arc(x, y, r, 0, 2 * Math.PI);
                CTX.fill();
                CTX.stroke();
            }
            if (this.loadBalancer) {
                CTX.beginPath();
                CTX.arc(x + this.s - r, y, r, 0, 2 * Math.PI);
                CTX.fill();
                CTX.stroke();
            }
            CTX.fillStyle = "white";
            CTX.textAlign = "center";
            if (this.firewall) {
                CTX.fillText("", x, y + s / 2 - 2);
            }
            if (this.loadBalancer) {
                CTX.fillText("", x + this.s - r, y + s / 2 - 3);
            }
        }
        if (HCI.key.n) {
            CTX.font = "16px PT Sans Narrow";
            CTX.fillStyle = Color.darkblue;
            CTX.lineWidth = 1;
            CTX.strokeStyle = "white";
            CTX.strokeText(this.name + " " + this.ip, this.s / 2, 0);
            CTX.fillText(this.name + " " + this.ip, this.s / 2, 0);
        }
        CTX.restore();
    }
    function computeLoad() {
        var i, link;
        var load = 0;
        var bandwidth = 0;
        if (this.icon === "router") {
            for (i = this.links.length - 1; i >= 0; --i) {
                link = this.links[i];
                load += link.load;
                bandwidth += link.bandwidth;
            }
            this.color = load / bandwidth > .9 ? "#DF3A01" : load / bandwidth > .7 ? "#DF7401" : load / bandwidth > .5 ? "#DBA901" : load / bandwidth > .3 ? "#D7DF01" : load / bandwidth > 0 ? "#A5DF00" : "#FFFFFF";
        }
    }
    function isOver(x, y, dx, dy) {
        if (dx === undefined) {
            if (this.x - this.s / 2 <= x && x <= this.x + this.s / 2) {
                if (this.y - this.s / 2 <= y && y <= this.y + this.s / 2) {
                    this.isSelected = true;
                    return true;
                }
            }
        } else {
            if (this.x <= Math.max(x, x + dx) && this.x >= Math.min(x, x + dx) && this.y <= Math.max(y, y + dy) && this.y >= Math.min(y, y + dy)) {
                this.isSelected = true;
                return true;
            }
        }
        return false;
    }
}();

"use strict";

var Info = function() {
    var main, controller;
    return {
        init: init
    };
    function init() {
        main = document.getElementsByTagName("main")[0];
        Server.ajax("GET", "/api/controller-manager/info", display);
    }
    function display(response) {
        var i, len, us, max = 0, html = "", uptime;
        controller = {
            address: response && response.address || "0.0.0.0",
            port: response && response.port || 0,
            threads: response && response.nthreads || 0,
            secure: response && response.secure || false,
            logLevel: response && response.logLevel || "HIGH",
            started: response && response.started || 0
        };
        uptime = Math.round(Date.now() / 1e3 - controller.started);
        window.console.info("uptime", uptime);
        html += "<h1>Info</h1>";
        html += "<h2>Run Options</h2>";
        html += "<ul>";
        html += "<li><u>address</u><i>" + controller.address + "</i></li>";
        html += "<li><u>port</u><i>" + controller.port + "</i></li>";
        html += "<li><u>threads</u><i>" + controller.threads + "</i></li>";
        html += "<li><u>log level</u><i>" + controller.logLevel + "</i></li>";
        html += "</ul>";
        html += "<h2>Statistics</h2>";
        html += "<ul>";
        html += "<li><u>uptime</u><i>" + uptime + " sec</i></li>";
        html += "</ul>";
        main.innerHTML = html;
        us = main.querySelectorAll("u");
        for (i = 0, len = us.length; i < len; ++i) {
            if (us[i].offsetWidth > max) {
                max = us[i].offsetWidth;
            }
        }
        for (i = 0, len = us.length; i < len; ++i) {
            us[i].style.width = max + "px";
        }
    }
}();

"use strict";

newLink = function() {
    var MaxBandwidth = 4e8;
    var MaxD = 5;
    return function(ex) {
        ex = ex || {};
        var link = {
            type: "link",
            id: ex.id || "DEFAULT",
            bandwidth: ex.bandwidth || 2e8,
            host1: Net.getHostByID(ex.host1) || false,
            host2: Net.getHostByID(ex.host2) || false,
            host1_p: ex.host1_p || false,
            host2_p: ex.host2_p || false,
            isSelected: false,
            load: false,
            draw: draw,
            other: other,
            isOver: isOver
        };
        Net.add(link);
        link.host1.links.push(link);
        link.host2.links.push(link);
        return link;
    };
    function draw() {
        if (!this.host1 || !this.host2) {
            window.console.error("Empty link");
            return;
        }
        CTX.save();
        CTX.beginPath();
        CTX.moveTo(this.host1.x, this.host1.y);
        CTX.lineTo(this.host2.x, this.host2.y);
        if (this.isSelected) {
            CTX.lineWidth = 15;
            CTX.strokeStyle = Color.blue;
            CTX.stroke();
        }
        CTX.lineWidth = this.bandwidth / MaxBandwidth * 10;
        CTX.strokeStyle = this.load ? this.load / this.bandwidth > .9 ? "#DF3A01" : this.load / this.bandwidth > .7 ? "#DF7401" : this.load / this.bandwidth > .5 ? "#DBA901" : this.load / this.bandwidth > .3 ? "#D7DF01" : "#A5DF00" : "black";
        CTX.stroke();
        CTX.restore();
    }
    function other(host) {
        return host === this.host1 ? this.host2 : this.host1;
    }
    function isOver(x, y) {
        var x1 = this.host1.x, x2 = this.host2.x, y1 = this.host1.y, y2 = this.host2.y, a = y1 - y2, b = x2 - x1, c = x1 * (y2 - y1) - y1 * (x2 - x1), d = Math.abs(a * x + b * y + c) / Math.sqrt(a * a + b * b);
        if (d < MaxD) {
            if (x < MaxD + Math.max(x1, x2) && x > Math.min(x1, x2) - MaxD && y < MaxD + Math.max(y1, y2) && y > Math.min(y1, y2) - MaxD) {
                if (HCI.key.ctrl && !this.belongsToRouter()) {
                    return false;
                }
                this.isSelected = true;
                return true;
            }
        }
        return false;
    }
}();

"use strict";

(function() {
    var width;
    var height;
    var now;
    var then;
    window.addEventListener("resize", function() {
        var width = document.body.clientWidth;
        var height = document.body.clientHeight;
    });
    document.addEventListener("DOMContentLoaded", function() {
        Server.ajax("GET", "/apps", Net.appList);
        if (document.body.className === "enterprise") {
            UI.init();
            document.getElementsByTagName("html")[0].style.height = window.innerHeight - 10 + "px";
            width = UI.canvas.parentNode.offsetWidth;
            height = UI.canvas.parentNode.offsetHeight;
            UI.centerX = width / 2;
            UI.centerY = height / 2;
            UI.canvas.width = width;
            UI.canvas.height = height;
            if (UI.canvas.getContext) {
                CTX = UI.canvas.getContext("2d");
                now = Date.now();
                HCI.init();
                Net.init();
                onIconsLoaded(function() {
                    window.requestAnimationFrame(main);
                });
            }
        } else if (document.body.className === "info") {
            Info.init();
        } else if (document.body.className === "switch") {
            Switch.init();
        } else if (document.body.className === "start") {
            width = window.innerWidth;
            height = window.innerHeight;
            document.getElementsByTagName("html")[0].style.height = height + "px";
            UI.canvas = document.getElementsByClassName("sign-in")[0];
            UI.canvas.style.left = width / 2 - UI.canvas.getBoundingClientRect().width / 2 + "px";
            UI.canvas.style.top = height / 2 - UI.canvas.getBoundingClientRect().height / 2 + "px";
            document.getElementsByTagName("button")[0].onclick = function() {
                window.location = "topology.html";
            };
        }
    });
    function main() {
        then = now;
        now = Date.now();
        var delta = (now - then) / 1e3;
        update(delta);
        render();
        window.requestAnimationFrame(main);
    }
    function update(delta) {
        return delta;
    }
    function render() {
        CTX.fillStyle = "#FAFAFA";
        CTX.fillRect(0, 0, width, height);
        HCI.draw("before");
        Net.draw();
        HCI.draw("after");
    }
    function onIconsLoaded(callback) {
        var names = [ "aboss", "acloud128", "acloud256", "acloud512", "acloudapp128", "acloudapp256", "acloudapp512", "adatabase", "adatabase2", "adatabase3", "adatabase4", "adatabase5", "aimac", "amacair", "amacblack", "amacpro", "amacwhite", "amonitor", "aplanet128", "aplanet256", "aplanet512", "cloud", "cloud2", "cloud3", "database", "database2", "firewall", "firewall2", "hub", "hub2", "lan", "laptop", "linux", "linux2", "mac", "mac2", "ok", "ok2", "pc", "pc2", "router", "router2", "server", "server2", "storage", "storage2", "sync", "user", "win", "win2", "workstation", "workstation2", "www", "www2" ];
        var name;
        var i, q = names.length;
        for (i = 0; i < q; ++i) {
            name = names[i];
            UI.icons[name] = {};
            UI.icons[name].ready = false;
        }
        for (i = 0; i < q; ++i) {
            name = names[i];
            UI.icons[name].img = new Image();
            UI.icons[name].img.src = "images/" + name + ".png";
            UI.icons[name].img.addEventListener("load", onLoad(name));
        }
        function onLoad(name) {
            UI.icons[name].ready = true;
            if (areAllReady()) {
                callback();
            }
        }
        function areAllReady() {
            var allReady = true;
            var i, q = names.length;
            for (i = 0; i < q; ++i) {
                name = names[i];
                if (!UI.icons[name].ready) {
                    allReady = false;
                }
            }
            return allReady;
        }
    }
})();

"use strict";

Net = function() {
    var hosts = [], links = [], last_ev = 0;
    return {
        hosts: hosts,
        links: links,
        last_ev: last_ev,
        init: init,
        save: save,
        clear: clear,
        add: add,
        del: del,
        draw: draw,
        getHostByID: getHostByID,
        getLinkByID: getLinkByID,
        positions: positions,
        appList: appList,
        newPos: newPos,
        newDevPos: newDevPos,
        getPosition: getInfo,
        getLinkByPort: getLinkByPort
    };
    function getInfo(response) {
        if (!response.ID) return;
        var obj = getHostByID(response.ID);
        obj.name = response.display_name;
        if (response.x_coord < 0 || response.y_coord < 0) {
            var coords;
            if (obj.type === "router") coords = newPos(); else {
                var sw_obj = obj.links[0].host1 != obj ? obj.links[0].host1 : obj.links[0].host2;
                coords = newDevPos(sw_obj.id);
            }
            obj.x = coords.x;
            obj.y = coords.y;
        } else {
            obj.fixed_pos = true;
            obj.x = response.x_coord;
            obj.y = response.y_coord;
        }
    }
    function newPos() {
        var res = new Object(), cx = Math.round(UI.centerX), cy = Math.round(UI.centerY), pi = 3.14, count = 0, rad = Math.min(UI.centerX / 2, UI.centerY / 2);
        if (hosts.length == 0) {
            res.x = cx;
            res.y = cy;
            return res;
        }
        for (var i = 0; i < hosts.length; i++) if (hosts[i].type === "router") ++count;
        for (var i = 0; i < count - 1; i++) {
            if (!hosts[i].fixed_pos) {
                hosts[i].x = Math.round(rad * Math.cos(2 * pi * i / count - pi / 2) + cx);
                hosts[i].y = Math.round(rad * Math.sin(2 * pi * i / count - pi / 2) + cy);
            }
        }
        res.x = Math.round(rad * Math.cos(2 * pi * (count - 1) / count - pi / 2) + cx);
        res.y = Math.round(rad * Math.sin(2 * pi * (count - 1) / count - pi / 2) + cy);
        return res;
    }
    function newDevPos(switch_id) {
        var res = new Object(), sw = getHostByID(switch_id), rad = 150, cx = Math.round(UI.centerX), cy = Math.round(UI.centerY), pi = 3.14, angle = 0, rand = Math.floor(Math.random() * 8) * pi / 4;
        angle = Math.atan((sw.y - cy) / (sw.x - cx));
        res.x = Math.round(rad * Math.cos(angle + rand) + sw.x);
        res.y = Math.round(rad * Math.sin(angle + rand) + sw.y);
        return res;
    }
    function appList(response) {
        var ahtml = "", shtml = "";
        var srv_elem = document.getElementsByName("srv")[0];
        var apps_elem = document.getElementsByName("apps")[0];
        var body_class = document.title.toLowerCase();
        for (var app in response) {
            var page = response[app].page == "none" ? "#" : response[app].page;
            var cur = response[app].name.toLowerCase().indexOf(body_class) >= 0 || body_class.indexOf(response[app].name.toLowerCase()) >= 0 ? true : false;
            if (response[app].type == "Application") ahtml += "<a " + (cur == true ? 'class = "current"' : "") + ' href="' + page + '">' + response[app].name + "</a>";
            if (response[app].type == "Service") shtml += "<a " + (cur == true ? 'class = "current"' : "") + ' href="' + page + '">' + response[app].name + "</a>";
        }
        srv_elem.innerHTML = shtml;
        apps_elem.innerHTML = ahtml;
    }
    function init() {
        Server.ajax("GET", "/timeout/switch-manager&topology&host-manager&flow-manager/" + last_ev, setNet);
        function setNet(response) {
            var _switches = [], _hosts = [], _links = [], _flow = [];
            var events = response["events"];
            last_ev = response["last_event"];
            if (events["switch-manager"]) _switches = events["switch-manager"];
            if (events["topology"]) _links = events["topology"];
            if (events["host-manager"]) _hosts = events["host-manager"];
            if (events["flow-manager"]) _flow = events["flow-manager"];
            var i, len;
            for (i = 0, len = _switches.length; i < len; ++i) {
                if (_switches[i].type == "Add") {
                    var h = newHost({
                        id: _switches[i].obj_id,
                        name: _switches[i].obj_info.DPID,
                        icon: "router"
                    });
                    Server.ajax("GET", "/api/webui/webinfo/" + _switches[i].obj_id, getInfo);
                } else if (_switches[i].type == "Delete") {
                    var obj = getHostByID(_switches[i].obj_id);
                    for (var j = 0, llen = obj.links.length; j < llen; ++j) {
                        Net.del(obj.links[j]);
                    }
                    Net.del(obj);
                }
            }
            for (i = 0, len = _links.length; i < len; ++i) {
                if (_links[i].type == "Add") newLink({
                    id: _links[i].obj_id,
                    host1: _links[i].obj_info.connect[0].src_id,
                    host2: _links[i].obj_info.connect[1].dst_id,
                    host1_p: _links[i].obj_info.connect[0].src_port,
                    host2_p: _links[i].obj_info.connect[1].dst_port
                }); else if (_links[i].type == "Delete") {
                    var obj = getLinkByID(_links[i].obj_id);
                    Net.del(obj);
                }
            }
            for (i = 0, len = _hosts.length; i < len; ++i) {
                if (_hosts[i].type == "Add") {
                    newHost({
                        id: _hosts[i].obj_id,
                        name: _hosts[i].obj_info.mac,
                        icon: "aimac"
                    });
                    Server.ajax("GET", "/api/webui/webinfo/" + _hosts[i].obj_id, getInfo);
                    newLink({
                        id: Math.random() * (2e3 - 1e3) + 1e3,
                        host1: _hosts[i].obj_id,
                        host2: _hosts[i].obj_info.switch_id,
                        host2_p: _hosts[i].obj_info.switch_port
                    });
                } else if (_hosts[i].type == "Delete") {
                    var obj = getHostByID(_hosts[i].obj_id);
                    Net.del(obj);
                }
            }
            for (i = 0, len = _flow.length; i < len; ++i) {
                var sw = getHostByID(_flow[i].obj_info.switch_id);
                if (sw == null || sw.type != "router") {
                    window.console.error("Not a switch");
                    continue;
                }
                if (_flow[i].type == "Add") {
                    var eth_src = _flow[i].obj_info.eth_src != "00:00:00:00:00:00" ? _flow[i].obj_info.eth_src : "", eth_dst = _flow[i].obj_info.eth_dst != "ff:ff:ff:ff:ff:ff" ? _flow[i].obj_info.eth_dst : "BROADCAST", out_port = _flow[i].obj_info.out_port != -4 ? _flow[i].obj_info.out_port : "ALL", in_port = _flow[i].obj_info.in_port, ip_src = _flow[i].obj_info.ip_src, ip_dst = _flow[i].obj_info.ip_dst, set_field = _flow[i].obj_info.set_field;
                    var actions = "";
                    var j, len2;
                    for (j = 0, len2 = out_port.length; j < len2; ++j) {
                        if (out_port[j] == -3) {
                            out_port[j] = "to-controller";
                        } else if (out_port[j] == -5) {
                            out_port[j] = "FLOOD";
                        }
                    }
                    if (out_port.length == 0) out_port = "drop"; else out_port = "output: " + out_port;
                    actions += out_port;
                    if (set_field.length != 0) {
                        set_field = set_field[0];
                        for (var key in set_field) {
                            actions += "<br>set_field: " + set_field[key] + " -> " + key;
                        }
                    }
                    eth_dst = eth_dst != "00:00:00:00:00:00" ? eth_dst : "";
                    ip_src = ip_src != "0.0.0.0" ? ip_src : "";
                    ip_dst = ip_dst != "0.0.0.0" ? ip_dst : "";
                    var rule = {
                        id: _flow[i].obj_id,
                        in_port: in_port,
                        mac_src: eth_src,
                        mac_dst: eth_dst,
                        ip_src: ip_src,
                        ip_dst: ip_dst,
                        action: actions
                    };
                    sw.routingRules.set(_flow[i].obj_id, rule);
                } else if (_flow[i].type == "Delete") {
                    sw.routingRules.delete(_flow[i].obj_id);
                }
            }
        }
        setTimeout(init, 1e3);
    }
    function add(obj) {
        if (obj.type === "host" || obj.type === "router") {
            this.hosts.push(obj);
        } else if (obj.type === "link") {
            this.links.push(obj);
        }
    }
    function del(obj) {
        if (obj == null) return;
        if (obj.type === "host" || obj.type === "router") {
            for (var i = 0, len = hosts.length; i < len; ++i) {
                if (hosts[i].id == obj.id) {
                    hosts.splice(i, 1);
                    return;
                }
            }
        } else if (obj.type === "link") {
            for (var i = 0, len = links.length; i < len; ++i) {
                if (links[i].id == obj.id) {
                    if (links[i].host1.type == "host") {
                        del(links[i].host1);
                    }
                    if (links[i].host2.type == "host") {
                        del(links[i].host2);
                    }
                    links.splice(i, 1);
                    return;
                }
            }
        }
    }
    function draw() {
        var i;
        CTX.save();
        for (i = Net.links.length - 1; i >= 0; --i) {
            links[i].draw();
        }
        for (i = Net.hosts.length - 1; i >= 0; --i) {
            hosts[i].draw();
        }
        CTX.restore();
    }
    function positions() {
        var i;
        for (i = Net.hosts.length - 1; i >= 0; --i) {
            window.console.info(Net.hosts[i].name, Net.hosts[i].x, Net.hosts[i].y);
        }
    }
    function getLinkByID(id) {
        var i, len;
        for (i = 0, len = links.length; i < len; ++i) {
            if (links[i].id === id) {
                return links[i];
            }
        }
    }
    function getLinkByPort(sw_id, port_no) {
        var sw = getHostByID(sw_id);
        if (sw && sw.type === "router") {
            for (var i = 0, len = sw.links.length; i < len; ++i) {
                if (sw.links[i].host1.id == sw_id && sw.links[i].host1_p == port_no || sw.links[i].host2.id == sw_id && sw.links[i].host2_p == port_no) return sw.links[i];
            }
        }
    }
    function getHostByID(id) {
        var i, len;
        for (i = 0, len = hosts.length; i < len; ++i) {
            if (hosts[i].id === id) {
                return hosts[i];
            }
        }
        return null;
    }
    function save() {
        var i, len, j, jlen, t, json = {
            hosts: [],
            links: []
        };
        for (i = 0, len = hosts.length; i < len; ++i) {
            json.hosts.push({
                id: hosts[i].id,
                name: hosts[i].name,
                icon: hosts[i].icon,
                x: hosts[i].x,
                y: hosts[i].y,
                ip: hosts[i].ip,
                s: hosts[i].s
            });
        }
        for (i = 0, len = links.length; i < len; ++i) {
            json.links.push({
                id: links[i].id,
                host1: links[i].host1.id,
                host2: links[i].host2.id,
                bandwidth: links[i].bandwidth
            });
        }
        Server.ajax("POST", "dummy", json);
    }
    function clear() {
        hosts.length = 0;
        links.length = 0;
        last_ev = 0;
        if (UI.menu) UI.menu.style.display = "none";
        if (UI.aux) UI.aux.style.display = "none";
    }
}();

"use strict";

var Server = function() {
    var URL = "";
    return {
        ajax: ajax
    };
    function ajax(type, api, data, callback) {
        var past = Date.now(), request = new XMLHttpRequest();
        request.onreadystatechange = process;
        if (typeof data === "function") {
            callback = data;
            data = null;
        }
        if (api === "dummy") {
            if (callback) callback();
            return;
        }
        request.open(type, URL + api);
        if (type === "POST") {
            request.setRequestHeader("Content-Type", "application/json");
        }
        request.send(JSON.stringify(data));
        window.console.info("sent", type, URL, api, data);
        function process() {
            var response;
            if (request.readyState === 4) {
                if (request.status === 200) {
                    response = JSON.parse(request.responseText);
                    window.console.info("recieved", (Date.now() - past) / 1e3, api, response);
                    if (callback) {
                        callback(response);
                    }
                } else {
                    window.console.error("HTTP-ответ не 200. :-(");
                    Net.clear();
                }
            }
        }
    }
}();

"use strict";

var Switch = function() {
    var main, menu, clicked = false, switches;
    return {
        init: init
    };
    function init() {
        main = document.getElementsByTagName("main")[0];
        menu = document.getElementsByClassName("menu")[0];
        Server.ajax("GET", "/api/switch-manager/switches/all", displaySwitches);
    }
    function displaySwitches(response) {
        var html = main.innerHTML;
        if (response.length > 0) {
            html += "<h2>Switch Info</h2>";
            html += "<table>";
            html += "<tr>";
            html += "<th>DPID</th>";
            html += "<th>Manufacturer description</th>";
            html += "<th>Hardware description</th>";
            html += "<th>Software description</th>";
            html += "<th>Ports</th>";
            html += "</tr>";
            var i, len;
            for (i = 0, len = response.length; i < len; ++i) {
                html += "<tr>";
                html += "<td>" + response[i].DPID + "</td>";
                html += "<td>" + response[i].mfr_desc + "</td>";
                html += "<td>" + response[i].hw_desc + "</td>";
                html += "<td>" + response[i].sw_desc + "</td>";
                var ports = "";
                var j, llen;
                for (j = 0, llen = response[i].ports.length; j < llen; ++j) {
                    if (response[i].ports[j].portNumber > 0) {
                        ports += response[i].ports[j].name + " (" + response[i].ports[j].portNumber + ")";
                        ports += "<br>";
                    }
                }
                html += "<td>" + ports + "</td>";
                html += "</tr>";
            }
            main.innerHTML = html;
            menu = document.getElementsByClassName("menu")[0];
        }
        var table = document.getElementsByTagName("table")[0];
        table.addEventListener("contextmenu", function(e) {
            e.preventDefault();
            if (e.srcElement.localName == "td") showMenu(e.clientX - table.getBoundingClientRect().left + 30, e.clientY);
        });
    }
    function showMenu(x, y) {
        var html = "";
        html += '<li class="action sw_info">Switch info</li>';
        html += '<li class="action port_info">Ports info</li>';
        html += '<li class="action flow_info">Flow table</li>';
        menu.innerHTML = html;
        menu.style.left = x + "px";
        menu.style.top = y + "px";
        menu.style.display = "block";
        if (menu.querySelector(".sw_info")) {
            menu.querySelector(".sw_info").onmousedown = showSwitchInfo;
        }
        if (menu.querySelector(".port_info")) {
            menu.querySelector(".sw_info").onmousedown = showPortInfo;
        }
        if (menu.querySelector(".flow_info")) {
            menu.querySelector(".sw_info").onmousedown = showFlowInfo;
        }
        main.onmousedown = onMouseDown;
        clicked = true;
    }
    function onMouseDown(event) {
        if (clicked) {
            menu.style.display = "none";
            clicked = false;
            main.onmousedown = "";
        }
    }
    function showSwitchInfo() {}
    function showPortInfo() {}
    function showFlowInfo() {}
}();

"use strict";

UI = function() {
    return {
        centerX: false,
        centerY: false,
        icons: {},
        aux: false,
        canvas: false,
        init: init,
        showDetails: showDetails,
        showMenu: showMenu,
        setStyle: setStyle,
        addRule: addRule
    };
    function init() {
        UI.aux = document.getElementsByClassName("aux")[0];
        UI.canvas = document.getElementsByClassName("map")[0];
        UI.menu = document.getElementsByClassName("menu")[0];
        UI.menu.addEventListener("contextmenu", function(event) {
            event.preventDefault();
        });
        UI.canvas.addEventListener("contextmenu", function(event) {
            event.preventDefault();
        });
    }
    function showMenu(hovered, x, y) {
        var i, len, t, html = "";
        if (hovered.type === "router") {
            html += '<li class="edit"><input type="text" value="' + hovered.name + '"><i class="off"></i></li>';
            html += "<li>" + hovered.ip + "</li>";
            html += '<li class="separator"></li>';
            html += '<li class="action settings">Router Settings</li>';
            html += '<li class="separator"></li>';
            html += '<li class="action firewall">Firewall<i class="' + (hovered.firewall ? "on" : "off") + '"></i></li>';
            html += '<li class="action loadBalancer">Load Balancer<i class="' + (hovered.loadBalancer ? "on" : "off") + '"></i></li>';
        } else if (hovered.type === "link") {
            if (HCI.state.balanceLoad) {
                html += '<li class="action loadBalancer">Balance Load</li>';
            } else {
                if (hovered.load) {
                    html += "<li>Load: " + (hovered.load / hovered.bandwidth * 100).toFixed(2) + "%</li>";
                }
                html += "<li>Bandwidth: " + hovered.bandwidth / 1e9 + "Gb</li>";
                html += '<li class="action settings">Сhannel Settings</li>';
            }
        } else if (hovered.type === "host") {
            html += '<li class="edit"><input type="text" value="' + hovered.name + '"><i class="off"></i></li>';
            html += "<li>" + hovered.ip + "</li>";
            html += '<li class="separator"></li>';
            html += '<li class="action settings">Host Settings</li>';
        }
        if (hovered.type !== "link" && hovered.type !== "route") {}
        UI.menu.innerHTML = html;
        UI.menu.switch_id = hovered.id;
        if (UI.menu.querySelector(".edit")) {
            UI.menu.querySelector(".edit").onkeypress = nameChanged;
        }
        if (UI.menu.querySelector(".settings")) {
            UI.menu.querySelector(".settings").onclick = showDetails;
        }
        if (UI.menu.querySelector(".delete")) {
            UI.menu.querySelector(".delete").onclick = deleteThis;
        }
        if (UI.menu.querySelector(".firewall")) {
            UI.menu.querySelector(".firewall").onclick = showFirewall;
        }
        if (UI.menu.querySelector(".loadBalancer")) {
            UI.menu.querySelector(".loadBalancer").onclick = showLoadBalancer;
        }
        t = UI.menu.querySelectorAll(".action i, .action.port");
        for (i = 0, len = t.length; i < len; ++i) {
            t[i].onclick = toggleFeature;
        }
        UI.menu.style.display = "block";
        t = UI.menu.querySelector("input");
        if (t) {
            t.onchange = function() {
                var t = document.createElement("span");
                t.innerHTML = this.value;
                this.parentNode.parentNode.insertBefore(t, this.parentNode);
                this.style.width = t.offsetWidth + 16 + "px";
                this.parentNode.parentNode.removeChild(t);
                hovered.name = this.value;
                Net.save();
            };
            t.onkeyup = t.onchange;
            t.onpaste = t.onchange;
            t.onchange();
        }
        UI.menu.style.left = (x + UI.menu.offsetWidth + UI.canvas.getBoundingClientRect().left < window.innerWidth ? x : window.innerWidth - UI.menu.offsetWidth - UI.canvas.getBoundingClientRect().left) + "px";
        UI.menu.style.top = (y + UI.menu.offsetHeight + UI.canvas.getBoundingClientRect().top < window.innerHeight ? y : window.innerHeight - UI.menu.offsetHeight - UI.canvas.getBoundingClientRect().top) + "px";
        function deleteThis() {
            UI.menu.style.display = "none";
            Net.save();
        }
        function toggleFeature() {
            var t, hovered = HCI.getHovered();
            if (this.className.indexOf("port") >= 0) {
                this.querySelector("i").onclick();
            } else {
                this.className = this.className === "on" ? "off" : "on";
                if (this.parentNode.className.indexOf("firewall") >= 0) {
                    hovered.firewall = !hovered.firewall;
                } else if (this.parentNode.className.indexOf("loadBalancer") >= 0) {
                    hovered.loadBalancer = !hovered.loadBalancer;
                }
            }
            event.stopPropagation();
        }
        function nameChanged() {
            var hovered = HCI.getHovered();
            this.querySelector("i").style.display = "block";
            this.querySelector("i").className = "on";
            this.querySelector("i").onclick = sendNewName;
        }
        function sendNewName() {
            var hovered = HCI.getHovered(), req = new Object();
            req.name = hovered.name;
            Server.ajax("PUT", "api/webui/name/" + hovered.id, req);
            this.className = "off";
            this.onclick = "";
            this.style.display = "none";
        }
    }
    function showFirewall() {
        var i, len, t, html = "", hovered = HCI.getHovered();
        html += "<h1>" + hovered.name + "</h1>";
        html += "<h2>" + hovered.ip + "</h2>";
        html += "<h3>Firewall Settings</h3>";
        html += "<table>";
        html += "<thead><tr>";
        html += "<th>action</th>";
        html += "<th>src_ip</th>";
        html += "<th>proto</th>";
        html += "<th>dest_ip</th>";
        html += "<th>dest_port</th>";
        html += "</tr></thead>";
        html += "<tbody>";
        for (i = 0, len = hovered.firewallRules.length; i < len; ++i) {
            t = hovered.firewallRules[i];
            html += "<tr>";
            html += "<td>" + (t.action ? t.action : "") + "</td>";
            html += "<td>" + (t.src_ip ? t.src_ip : "") + "</td>";
            html += "<td>" + (t.proto ? t.proto : "") + "</td>";
            html += "<td>" + (t.dest_ip ? t.dest_ip : "") + "</td>";
            html += "<td>" + (t.dest_port ? t.dest_port : "") + "</td>";
            html += "</tr>";
        }
        html += "</tbody>";
        html += "<tfoot>";
        html += "<tr><td>";
        html += '<button type="button" class="add">Add Rule</button>';
        html += "</td></tr>";
        html += "</tfoot>";
        html += "</table>";
        html += '<button type="button" class="remove"></button>';
        UI.aux.innerHTML = html;
        UI.aux.className = "firewall";
        t = UI.aux.querySelectorAll("tbody tr");
        for (i = 0, len = t.length; i < len; ++i) {
            t[i].onmouseover = showRemoveRuleButton;
            t[i].onmouseout = hideRemoveRuleButton;
        }
        UI.aux.querySelector("button.add").onclick = showRowToAdd;
        UI.aux.querySelector("button.remove").onclick = removeRule;
        UI.menu.style.display = "none";
        UI.aux.style.display = "block";
    }
    function showLoadBalancer() {
        var i, len, t, html = "", hovered;
        if (HCI.state.balanceLoad) {
            hovered = HCI.state.balanceLoad;
        } else {
            hovered = HCI.getHovered();
        }
        html += "<h1>" + hovered.name + "</h1>";
        html += "<h2>" + hovered.ip + "</h2>";
        html += "<h3>Load Balancer Settings</h3>";
        html += "<table>";
        html += "<thead><tr>";
        html += "<th>protocol</th>";
        html += "<th>src_ips</th>";
        html += "<th>dest_ips</th>";
        html += "<th>dest_ports</th>";
        html += "</tr></thead>";
        html += "<tbody>";
        for (i = 0, len = hovered.balancingRules.length; i < len; ++i) {
            t = hovered.balancingRules[i];
            html += "<tr>";
            html += "<td>" + (t.protocol ? t.protocol : "") + "</td>";
            html += "<td>" + (t.src_ips ? t.src_ips : "") + "</td>";
            html += "<td>" + (t.dest_ips ? t.dest_ips : "") + "</td>";
            html += "<td>" + (t.dest_ports ? t.dest_ports : "") + "</td>";
            html += "</tr>";
        }
        html += "</tbody>";
        html += "<tfoot>";
        html += "<tr><td>";
        html += '<button type="button" class="add">Add Rule</button>';
        html += "</td></tr>";
        html += "</tfoot>";
        html += "</table>";
        html += '<button type="button" class="remove"></button>';
        UI.aux.innerHTML = html;
        UI.aux.className = "loadBalancer";
        t = UI.aux.querySelectorAll("tbody tr");
        for (i = 0, len = t.length; i < len; ++i) {
            t[i].onmouseover = showRemoveRuleButton;
            t[i].onmouseout = hideRemoveRuleButton;
        }
        UI.aux.querySelector("button.add").onclick = showRowToAdd;
        UI.aux.querySelector("button.remove").onclick = removeRule;
        UI.menu.style.display = "none";
        UI.aux.style.display = "block";
    }
    function showDetails() {
        var i, len, t, html = "", hovered = HCI.getHovered();
        html += "<h1>" + hovered.name + "</h1>";
        html += "<h2>" + hovered.ip + "</h2>";
        html += "<h3>Network Switch Table</h3>";
        html += "<table>";
        html += "<thead><tr>";
        html += "<th width=5%>in_port</th>";
        html += "<th width=15%>mac_src</th>";
        html += "<th width=15%>mac_dst</th>";
        html += "<th width=12%>ip_src</th>";
        html += "<th width=12%>ip_dst</th>";
        html += "<th width=5%>ip_proto</th>";
        html += "<th width=5%>ip_tos</th>";
        html += "<th width=5%>src_port</th>";
        html += "<th width=5%>dst_port</th>";
        html += "<th width=21%>action</th>";
        html += "</tr></thead>";
        html += "<tbody>";
        function fillRules(value, key, map) {
            t = value;
            html += "<tr>";
            html += "<td width=5%>" + (t.in_port ? t.in_port : "") + "</td>";
            html += "<td width=15%>" + (t.mac_src ? t.mac_src : "") + "</td>";
            html += "<td width=15%>" + (t.mac_dst ? t.mac_dst : "") + "</td>";
            html += "<td width=12%>" + (t.ip_src ? t.ip_src : "") + "</td>";
            html += "<td width=12%>" + (t.ip_dst ? t.ip_dst : "") + "</td>";
            html += "<td width=5%>" + (t.ip_proto ? t.ip_proto : "") + "</td>";
            html += "<td width=5%>" + (t.ip_tos ? t.ip_tos : "") + "</td>";
            html += "<td width=5%>" + (t.src_port ? t.src_port : "") + "</td>";
            html += "<td width=5%>" + (t.dst_port ? t.dst_port : "") + "</td>";
            html += "<td width=21%>" + (t.action ? t.action : "") + "</td>";
            html += "</tr>";
        }
        hovered.routingRules.forEach(fillRules);
        html += "</tbody>";
        html += "<tfoot>";
        html += "<tr><td>";
        html += '<button type="button" class="add">Add Rule</button>';
        html += "</td></tr>";
        html += "</tfoot>";
        html += "</table>";
        html += '<button type="button" class="remove"></button>';
        html += '<button type="button" class="new"></button>';
        UI.aux.innerHTML = html;
        UI.aux.className = "hostinfo";
        t = UI.aux.querySelectorAll("tbody tr");
        for (i = 0, len = t.length; i < len; ++i) {
            t[i].onmouseover = showRemoveRuleButton;
            t[i].onmouseout = hideRemoveRuleButton;
        }
        UI.aux.querySelector("button.add").onclick = showRowToAdd;
        UI.aux.querySelector("button.remove").onclick = removeRule;
        UI.menu.style.display = "none";
        UI.aux.style.display = "block";
    }
    function addNewActionLine() {
        var new_line = document.getElementsByName("action_line")[0].cloneNode(true);
        document.getElementById("actions_container").appendChild(new_line);
        var last = document.getElementsByName("action_line").length - 1;
        var act = document.getElementsByName("action")[last];
        act.onchange = function() {
            if (act.value == "output") {
                document.getElementsByName("mod_field")[last].style.display = "none";
                document.getElementsByName("mod_field_value")[last].style.display = "none";
                document.getElementsByName("outport")[last].style.display = "inline";
            }
            if (act.value == "set_field") {
                document.getElementsByName("outport")[last].style.display = "none";
                document.getElementsByName("mod_field")[last].style.display = "inline";
                document.getElementsByName("mod_field")[last].onchange = function() {
                    document.getElementsByName("mod_field_value")[last].style.display = "inline";
                };
            }
            if (act.value == "drop") {
                document.getElementsByName("outport")[last].style.display = "none";
                document.getElementsByName("mod_field")[last].style.display = "none";
                document.getElementsByName("mod_field_value")[last].style.display = "none";
            }
        };
        document.getElementsByName("action_line")[last].style.display = "block";
    }
    function showRowToAdd() {
        var i, len, html = "", t = UI.aux.querySelector("tbody");
        html += "<tr>";
        if (UI.aux.className === "hostinfo") {
            html += '<td width=5%><input type="text" placeholder="in_port"></td>';
            html += '<td width=15%><input type="text" placeholder="mac_src"></td>';
            html += '<td width=15%><input type="text" placeholder="mac_dst"></td>';
            html += '<td width=12%><input type="text" placeholder="ip_src"></td>';
            html += '<td width=12%><input type="text" placeholder="ip_dst"></td>';
            html += '<td width=5%><input type="text" placeholder="ip_proto"></td>';
            html += '<td width=5%><input type="text" placeholder="ip_tos"></td>';
            html += '<td width=5%><input type="text" placeholder="src_port"></td>';
            html += '<td width=5%><input type="text" placeholder="dst_port"></td>';
            html += '<td width=21%><div id="actions_container" style="display:inline; position:relative">';
            html += '<input type="submit" style="width:auto" id="add_new_line" value="New action...">';
            html += '<div name="action_line" style="display:none; position:relative">';
            html += '<select size="1" name="action">';
            html += "<option disabled selected  > action </option>";
            html += '<option value="output"> output </option>';
            html += '<option value="set_field"> set_field </option>';
            html += '<option value-"drop"> drop </option>';
            html += "</select>";
            html += '<input type="text" placeholder="port" name="outport" style="display:none; width:40px">';
            html += '<select name="mod_field" style="display:none">';
            html += "<option disabled selected  > field </option>";
            html += '<option value="eth_src"> eth_src </option>';
            html += '<option value="eth_dst"> eth_dst </option>';
            html += '<option value="ip_src"> ip_src </option>';
            html += '<option value="ip_dst"> ip_dst </option>';
            html += "</select>";
            html += '<input type="text" placeholder="value" name="mod_field_value" style="display:none; width:auto">';
            html += "</div>";
            html += "</div></td>";
        } else if (UI.aux.className === "firewall") {
            html += '<td><input type="text" placeholder="action"></td>';
            html += '<td><input type="text" placeholder="src_ip"></td>';
            html += '<td><input type="text" placeholder="proto"></td>';
            html += '<td><input type="text" placeholder="dest_ip"></td>';
            html += '<td><input type="text" placeholder="dest_port"></td>';
        } else if (UI.aux.className === "loadBalancer") {
            html += '<td><input type="text" placeholder="protocol"></td>';
            html += '<td><input type="text" placeholder="src_ips"></td>';
            html += '<td><input type="text" placeholder="dest_ips"></td>';
            html += '<td><input type="text" placeholder="dest_ports"></td>';
        }
        html += "</tr>";
        t.innerHTML += html;
        document.getElementById("add_new_line").onclick = addNewActionLine;
        addNewActionLine();
        t = UI.aux.querySelectorAll("tbody tr");
        len = t.length;
        var button = UI.aux.querySelector("button.new");
        button.style.top = t[len - 1].getBoundingClientRect().top - UI.aux.getBoundingClientRect().top - 1 + "px";
        button.style.left = "10px";
        button.style.display = "block";
        button.onclick = addRule;
        var button = UI.aux.querySelector("button.remove");
        button.style.top = t[len - 1].getBoundingClientRect().top - UI.aux.getBoundingClientRect().top - 1 + "px";
        button.style.left = t[len - 1].getBoundingClientRect().right - UI.aux.getBoundingClientRect().left + "px";
        button.style.display = "block";
        var button = UI.aux.querySelector("button.add");
        button.style.display = "none";
    }
    function addRule() {
        var rows = UI.aux.querySelectorAll("tbody tr"), i, row = rows[rows.length - 1], hovered = HCI.getHovered(), items = row.querySelectorAll("td");
        if (UI.aux.className == "hostinfo") {
            var mac_regex = /^([a-f0-9]{2}(:|-)){5}[a-f0-9]{2}$/gi;
            var ip_regex = /^(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])$/g;
            var in_port = items[0].querySelector("input").value, mac_src = items[1].querySelector("input").value.toLowerCase(), mac_dst = items[2].querySelector("input").value.toLowerCase(), ip_src = items[3].querySelector("input").value, ip_dst = items[4].querySelector("input").value, ip_proto = items[5].querySelector("input").value, ip_tos = items[6].querySelector("input").value, src_port = items[7].querySelector("input").value, dst_port = items[8].querySelector("input").value, action = document.getElementsByName("action");
            if (!(in_port || mac_src || mac_dst || ip_src || ip_dst || ip_proto || ip_tos || src_port || dst_port || action)) {
                return;
            }
            if (mac_src && mac_src.search(mac_regex) == -1) {
                alert("Incorrect mac_src: " + mac_src);
                return;
            }
            if (mac_dst && mac_dst.search(mac_regex) == -1) {
                alert("Incorrect mac_dst: " + mac_dst);
                return;
            }
            if (ip_src && ip_src.search(ip_regex) == -1) {
                alert("Incorrect ip_src: " + ip_src);
                return;
            }
            if (ip_dst && ip_dst.search(ip_regex) == -1) {
                alert("Incorrect ip_dst: " + ip_dst);
                return;
            }
            if (isNaN(Number(in_port))) {
                alert("Incorrect in_port: " + in_port);
                return;
            }
            if (isNaN(Number(src_port))) {
                alert("Incorrect src_port: " + src_port);
                return;
            }
            if (isNaN(Number(dst_port))) {
                alert("Incorrect dst_port: " + dst_port);
                return;
            }
            var actions_list = new Object();
            for (var l = 0; l < action.length; l++) {
                if (action[l].value == "output") {
                    var port = document.getElementsByName("outport")[l].value;
                    if (isNaN(Number(port))) {
                        alert("Incorrect value: " + port);
                        return;
                    }
                    actions_list[action[l].value] = port;
                } else if (action[l].value == "set_field") {
                    var field = document.getElementsByName("mod_field")[l].value, value = document.getElementsByName("mod_field_value")[l].value;
                    if ((field == "eth_src" || field == "eth_dst") && value.search(mac_regex) == -1) {
                        alert("Incorrect mac address: " + value);
                        return;
                    }
                    if ((field == "ip_src" || field == "ip_dst") && value.search(ip_regex) == -1) {
                        alert("Incorrect ip address: " + value);
                        return;
                    }
                    actions_list[field] = value;
                } else if (action[l].value == "drop") {
                    actions_list[action[l].value] = true;
                }
            }
            items[0].innerHTML = in_port;
            items[1].innerHTML = mac_src;
            items[2].innerHTML = mac_dst;
            items[3].innerHTML = ip_src;
            items[4].innerHTML = ip_dst;
            items[5].innerHTML = ip_proto;
            items[6].innerHTML = ip_tos;
            items[7].innerHTML = src_port;
            items[8].innerHTML = dst_port;
            items[9].innerHTML = "";
            for (var elem in actions_list) {
                if (elem == "output") {
                    items[9].innerHTML += elem + ": " + actions_list[elem] + "<br>";
                } else if (elem == "drop") {
                    items[9].innerHTML += "drop<br>";
                } else {
                    items[9].innerHTML += "set_field: " + actions_list[elem] + " -> " + elem + "<br>";
                }
            }
            var req = new Object();
            req.in_port = Number(in_port);
            req.eth_src = mac_src;
            req.eth_dst = mac_dst;
            req.ip_src = ip_src;
            req.ip_dst = ip_dst;
            req.ip_proto = ip_proto;
            req.ip_tos = ip_tos;
            req.src_port = Number(src_port);
            req.dst_port = Number(dst_port);
            if (!isNaN(Number(actions_list["output"]))) req.out_port = Number(actions_list["output"]);
            if (actions_list["eth_src"]) req.modify_eth_src = actions_list["eth_src"];
            if (actions_list["eth_dst"]) req.modify_eth_dst = actions_list["eth_dst"];
            if (actions_list["ip_src"]) req.modify_ip_src = actions_list["ip_src"];
            if (actions_list["ip_dst"]) req.modify_ip_dst = actions_list["ip_dst"];
            Server.ajax("POST", "/api/static-flow-pusher/newflow/" + UI.menu.switch_id, req);
        }
        UI.aux.querySelector("button.new").style.display = "none";
        UI.aux.querySelector("button.remove").style.display = "none";
        UI.aux.querySelector("button.add").style.display = "block";
    }
    function removeRule() {
        var i, len, t, rows = UI.aux.querySelectorAll("tbody tr"), rect = this.getBoundingClientRect();
        for (i = 0, len = rows.length; i < len; ++i) {
            t = rows[i].getBoundingClientRect();
            t = t.top + (t.bottom - t.top) / 2;
            if (t < rect.bottom && t > rect.top) {
                if (UI.aux.className === "hostinfo") {
                    var rulesEntries = HCI.getHovered().routingRules.entries();
                    for (var k = 0; k < i; k++) rulesEntries.next();
                    var tmp = rulesEntries.next().value;
                    if (tmp) {
                        var flow_id = tmp[0], switch_id = UI.menu.switch_id;
                        HCI.getHovered().routingRules.delete(flow_id);
                        Server.ajax("DELETE", "/api/flow-manager/" + switch_id + "/" + flow_id);
                    } else {
                        UI.aux.querySelector("button.new").style.display = "none";
                        UI.aux.querySelector("button.remove").style.display = "none";
                        UI.aux.querySelector("button.add").style.display = "block";
                    }
                } else if (UI.aux.className === "firewall") {} else if (UI.aux.className === "loadBalancer") {}
                rows[i].parentNode.removeChild(rows[i]);
                return;
            }
        }
    }
    function showRemoveRuleButton() {
        var button = UI.aux.querySelector("button.remove");
        button.style.top = this.getBoundingClientRect().top - UI.aux.getBoundingClientRect().top - 1 + "px";
        button.style.left = this.getBoundingClientRect().right - UI.aux.getBoundingClientRect().left + "px";
        button.style.display = "block";
    }
    function hideRemoveRuleButton() {
        var button = UI.aux.querySelector("button.remove"), rect = button.getBoundingClientRect();
        if (event.fromElement === button) {
            if (event.y < rect.top || event.y > rect.bottom || event.x > rect.right) {
                button.style.display = "none";
            }
        } else {
            if (event.y < rect.top || event.y > rect.bottom || event.x + 1 < rect.left || event.x > rect.right) {
                button.style.display = "none";
            }
        }
    }
    function setStyle(obj, prop, val) {
        obj.style[prop] = val;
        if (obj.style[prop].indexOf(val) < 0) {
            obj.style[prop] = "-webkit-" + val;
        }
        if (obj.style[prop].indexOf(val) < 0) {
            obj.style[prop] = "-moz-" + val;
        }
        if (obj.style[prop].indexOf(val) < 0) {
            obj.style[prop] = "-o-" + val;
        }
        if (obj.style[prop].indexOf(val) < 0) {
            window.console.error("Can not style", obj, prop, val);
        }
    }
}();