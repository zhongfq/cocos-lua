package kernel.plugins.talkingdata;

import android.app.Activity;
import android.app.Application;

import com.tendcloud.tenddata.Order;
import com.tendcloud.tenddata.TCAgent;
import com.tendcloud.tenddata.TDAccount;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import kernel.AppContext;
import kernel.LuaJ;
import kernel.PluginManager;

@SuppressWarnings("unused")
public class TalkingData {
    private static final String TAG = TalkingData.class.getName();

    static {
        PluginManager.registerPlugin(new PluginManager.Handler() {
            @Override
            public void onInit(Application app) {
                TCAgent.LOG_ON = true;
                TCAgent.init(app);
                TCAgent.setReportUncaughtExceptions(false);
                AppContext.registerFeature("talkingdata", true);
            }

            @Override
            public void onStart(Activity context) {
            }
        });
    }

    private static int _print = -1;

    private static Map<Integer, Order> _orderMap = new HashMap<>();
    private static int _orderCount = 0;

    private static Map<String, Object> toMap(String jsonstr) {
        if (jsonstr == null || jsonstr.length() == 0)
            return null;

        try {
            Map<String, Object> map = new HashMap<>();
            JSONObject obj = new JSONObject(jsonstr);
            Iterator<String> itor = obj.keys();
            while (itor.hasNext()) {
                String key = itor.next();
                Object value = obj.get(key);
                map.put(key, value);
            }
            return map;
        } catch (JSONException e) {
            e.printStackTrace();
            return null;
        }
    }

    private static JSONObject toJson(String jsonstr) {
        try {
            return new JSONObject(jsonstr);
        } catch (JSONException e) {
            return null;
        }
    }

    public static void setPrint(int print) {
        _print = print;
    }

    public static void print(final String str) {
        if (_print > 0) {
            final AppContext context = (AppContext) AppContext.getContext();
            LuaJ.invoke(_print, "[talkingdata] " + str);
        }
    }

    public static void setLogEnabled(final boolean value) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.LOG_ON = value;
                print("set log enabled: " + value);
            }
        });
    }

    public static void setAntiCheatingEnabled(final boolean value) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.setAntiCheatingEnabled(context, value);
                print("set anti cheating enabled: " + value);
            }
        });
    }

    public static void init(final String appkey, final String channel) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.init(context.getApplicationContext(), appkey, channel);
                print("init: " + appkey + " " + channel);
            }
        });
    }

    private static TDAccount.AccountType getType(int type) {
        if (type == 0)
            return TDAccount.AccountType.ANONYMOUS;
        else if (type == 1)
            return TDAccount.AccountType.REGISTERED;
        else if (type == 2)
            return TDAccount.AccountType.SINA_WEIBO;
        else if (type == 3)
            return TDAccount.AccountType.QQ;
        else if (type == 4)
            return TDAccount.AccountType.QQ_WEIBO;
        else if (type == 5)
            return TDAccount.AccountType.ND91;
        else if (type == 6)
            return TDAccount.AccountType.WEIXIN;
        else if (type == 11)
            return TDAccount.AccountType.TYPE1;
        else if (type == 12)
            return TDAccount.AccountType.TYPE2;
        else if (type == 13)
            return TDAccount.AccountType.TYPE3;
        else if (type == 14)
            return TDAccount.AccountType.TYPE4;
        else if (type == 15)
            return TDAccount.AccountType.TYPE5;
        else if (type == 16)
            return TDAccount.AccountType.TYPE6;
        else if (type == 17)
            return TDAccount.AccountType.TYPE7;
        else if (type == 18)
            return TDAccount.AccountType.TYPE8;
        else if (type == 19)
            return TDAccount.AccountType.TYPE9;
        else if (type == 20)
            return TDAccount.AccountType.TYPE10;

        return TDAccount.AccountType.ANONYMOUS;
    }

    public static void onRegister(final String accountID, final int type, final String name) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.onRegister(accountID, getType(type), name);
                print("on register: " + accountID + " " + type + " " + name);
            }
        });
    }

    public static void onLogin(final String accountID, final int type, final String name) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.onLogin(accountID, getType(type), name);
                print("on login: " + accountID + " " + type + " " + name);
            }
        });
    }

    public static void setReportUncaughtExceptions(final boolean value) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.setReportUncaughtExceptions(value);
                print("set report nncaught exceptions: " + value);
            }
        });
    }

    public static void onPageStart(final String name) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.onPageStart(context, name);
                print("on page start: " + name);
            }
        });
    }

    public static void onPageEnd(final String name) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.onPageEnd(context, name);
                print("on page end: " + name);
            }
        });
    }

    public static void onEvent(final String event, final String label, final String kvStr) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                Map<String, Object> kv = toMap(kvStr);
                if (kv != null) {
                    TCAgent.onEvent(context, event, label, kv);
                    print("on event: " + event + " " + label + " " + kvStr);
                } else if (label.length() > 0) {
                    TCAgent.onEvent(context, event, label);
                    print("on event: " + event + " " + label);
                } else {
                    TCAgent.onEvent(context, event);
                    print("on event: " + event);
                }
            }
        });
    }

    public static void setGlobalKV(final String key, final int value) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.setGlobalKV(key, value);
                print("set global kv: " + key + " " + value);
            }
        });
    }

    public static void setGlobalKV(final String key, final boolean value) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.setGlobalKV(key, value);
                print("set global kv: " + key + " " + value);
            }
        });
    }

    public static void setGlobalKV(final String key, final String value) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.setGlobalKV(key, value);
                print("set global kv: " + key + " " + value);
            }
        });
    }

    public static void setGlobalKV(final String key, final double value) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.setGlobalKV(key, value);
                print("set global kv: " + key + " " + value);
            }
        });
    }

    public static void removeGlobalKV(final String key) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.removeGlobalKV(key);
                print("remove global kv: " + key);
            }
        });
    }

    public static int createOrder(String orderID, int total, String currencyType) {
        Order order = Order.createOrder(orderID, total, currencyType);
        int id = ++_orderCount;
        _orderMap.put(id, order);
        print("create order: " + orderID + " " + total + " " + currencyType);
        return id;
    }

    public static void removeOrder(int id) {
        _orderMap.remove(id);
    }

    public static void orderAddItem(int id, String itemID, String catalog, String name, int unitPrice, int amount) {
        if (_orderMap.containsKey(id)) {
            Order order = _orderMap.get(id);
            order.addItem(itemID, catalog, name, unitPrice, amount);
            print("order add item: " + itemID + " " + catalog + " " + name + " " + unitPrice + " " + amount);
        }
    }

    public static void onPlaceOrder(final String account, final int id) {
        if (_orderMap.containsKey(id)) {
            final AppContext context = (AppContext) AppContext.getContext();
            context.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    Order order = _orderMap.get(id);
                    TCAgent.onPlaceOrder(account, order);
                    print("on place order: " + account);
                }
            });
        }
    }

    public static void onOrderPaySucc(final String account, final String payType, final int id) {
        if (_orderMap.containsKey(id)) {
            final AppContext context = (AppContext) AppContext.getContext();
            context.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    Order order = _orderMap.get(id);
                    TCAgent.onOrderPaySucc(account, payType, order);
                    print("on order pay succ: " + account + " " + payType);
                }
            });
        }
    }
}