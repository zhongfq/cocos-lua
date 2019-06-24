local init = false
local function trace(str)
    str = string.gsub(str, 'CC_DLL ', '')
    str = string.gsub(str, 'CC_GUI_DLL ', '')
    local enum_cls
    print("local cls = class(M)")
    for line in string.gmatch(str, '[^\n\r]+') do
        if string.find(line, '^ *[/**]') or
            string.find(line, '^ *CC_DEPRECATED_ATTRIBUTE') or
            string.find(line, '^ */') or
            string.find(line, '^ *%*') then
            goto CONTINUE
        end
        if enum_cls then
            local s = string.gsub(line, '[{},;]', ' ')
            s = string.gsub(s, '^ *', '')
            s = string.gsub(s, ' *$', '')
            if #s > 0 then
                print('    ' .. s)
            end
            if string.find(line, '}') then
                enum_cls = nil
            end
            goto CONTINUE
        end
        local cls, super = string.match(line, 'enum +class *([^: ]+) *')
        if not cls then
            cls, super = string.match(line, 'class *([^: ]+) *: * public *([^ ,]+)')
        else
            enum_cls = cls
        end
        if not cls then
            cls = string.match(line, 'class *([^: ]+)')
        end
        if cls then
            if init then
                print("]]")
                print("")
                print("local cls = class(M)")
            end
            init = true
            print(string.format('cls.CPPCLS = "%s"', cls))
            print(string.format('cls.LUACLS = "%s"', cls))
            print(string.format('cls.SUPERCLS = "%s"', super))
            print("cls.funcs [[")
            goto CONTINUE
        end
        local func = string.match(line, '.+%(.*%)')
        if func then
            print(func)
        end

        ::CONTINUE::
    end
    print("]]")
end

trace [[
    class CC_DLL ProgressTimer : public Node
    {
    public:
        /** Types of progress
         * @since v0.99.1
         */
        enum class Type
        {
            RADIAL,/** Radial Counter-Clockwise. */
            BAR,/** Bar. */
        };
        
        /** Creates a progress timer with the sprite as the shape the timer goes through.
         *
         * @param sp The sprite as the shape the timer goes through.
         * @return A ProgressTimer.
         */
        static ProgressTimer* create(Sprite* sp);
    
        /** Change the percentage to change progress. 
         *
         * @return A Type
         */
        Type getType() const { return _type; }
    
        /** Percentages are from 0 to 100.
         *
         * @return Percentages.
         */
        float getPercentage() const { return _percentage; }
    
        /** The image to show the progress percentage, retain. 
         *
         * @return A sprite.
         */
        Sprite* getSprite() const { return _sprite; }
        
        /** Set the initial percentage values. 
         *
         * @param percentage The initial percentage values.
         */
        void setPercentage(float percentage);
        
        /** Set the sprite as the shape. 
         *
         * @param sprite The sprite as the shape.
         */
        void setSprite(Sprite *sprite);
        
        /** Set the ProgressTimer type. 
         *
         * @param type Is an Type.
         */
        void setType(Type type);
        
        /** Return the Reverse direction.
         *
         * @return If the direction is Anti-clockwise,it will return true.
         */
        bool isReverseDirection() { return _reverseDirection; };
        
        /** Set the Reverse direction.
         *
         * @param value If value is false it will clockwise,if is true it will Anti-clockwise.
         */
        void setReverseDirection(bool value);
    
        /** Set the Reverse direction.
         * @js setReverseDirection
         * @lua setReverseDirection
         * @param reverse If reverse is false it will clockwise,if is true it will Anti-clockwise.
         */
        CC_DEPRECATED_ATTRIBUTE void setReverseProgress(bool reverse) { setReverseDirection(reverse); }
    
    
        /**
         *    Midpoint is used to modify the progress start position.
         *    If you're using radials type then the midpoint changes the center point.
         *    If you're using bar type then the midpoint changes the bar growth.
         *        it expands from the center but clamps to the sprites edge so:
         *        you want a left to right then set the midpoint all the way to Vec2(0,y).
         *        you want a right to left then set the midpoint all the way to Vec2(1,y).
         *        you want a bottom to top then set the midpoint all the way to Vec2(x,0).
         *        you want a top to bottom then set the midpoint all the way to Vec2(x,1).
         * @param point A Vec2 point.
         */
        void setMidpoint(const Vec2& point);
        
        /** Returns the Midpoint. 
         *
         * @return A Vec2.
         */
        Vec2 getMidpoint() const;
    
        /**
         *    This allows the bar type to move the component at a specific rate.
         *    Set the component to 0 to make sure it stays at 100%.
         *    For example you want a left to right bar but not have the height stay 100%.
         *    Set the rate to be Vec2(0,1); and set the midpoint to = Vec2(0,.5f).
         * @param barChangeRate A Vec2.
         */
        void setBarChangeRate(const Vec2& barChangeRate ) { _barChangeRate = barChangeRate; }
        
        /** Returns the BarChangeRate.
         *
         * @return A barChangeRate.
         */
        Vec2 getBarChangeRate() const { return _barChangeRate; }
    
        // Overrides
        virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;
        virtual void setAnchorPoint(const Vec2& anchorPoint) override;
        virtual void setColor(const Color3B &color) override;
        virtual const Color3B& getColor() const override;
        virtual void setOpacity(GLubyte opacity) override;
        virtual GLubyte getOpacity() const override;
]]