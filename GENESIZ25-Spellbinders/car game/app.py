from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

if __name__ == "__main__":
    # Debug True for quick dev; you can change host="0.0.0.0" if needed
    app.run(debug=True)
